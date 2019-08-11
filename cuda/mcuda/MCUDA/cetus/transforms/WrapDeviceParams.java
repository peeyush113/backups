package cetus.transforms;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.analysis.*;
import cetus.exec.*;
import cetus.hir.*;
import cetus.transforms.MCUDAUtils;

/**
 * Interfaces a function call to the MCUDA runtime library.
 * First creates a type definition for this function's parameter 
 * structure.  
 * Then modifies the current function to now accept the implicit 
 * block and grid variables of the CUDA programming model, 
 * in addition to a pointer to an instance of the parameter structure.
 * Lastly, creates a new function with the original function 
 * signature, whose sole purpose is to construct the paramter 
 * structure, and pass the kernel invocation to the runtime.  
 * The kernel function is renamed and passed as one of the 
 * kernel invocation parameters.  
 */
public class WrapDeviceParams extends KernelTransformPass
{
  public String getPassName()
  {
    return new String("[WrapDeviceParams-MCUDA]");
  }

  public WrapDeviceParams(Program program)
  {
    super(program);
  }

  public void transformProcedure(Procedure proc)
  {
    //Some commonly used names and structures
    String interfaceName = proc.getName().toString();
    String kernelName = interfaceName + "__MCUDA_kernel";
    String paramStructName = kernelName + "_params";
    Identifier paramStructID = new Identifier(paramStructName);
    UserSpecifier paramStructType;
    TranslationUnit kernelFile = (TranslationUnit)proc.getParent();
    Iterator iter;
    // New body for the kernel function
    CompoundStatement oldbody = proc.getBody();
   
    //If it's an empty function, don't even bother.  Just remove the 
    //global specifier so it doesn't get processed later too.
    if(oldbody.getChildren().isEmpty())
      return;
    
    // Set up the structure for the parameters 

    if(Driver.getOptionValue("mcuda_nolib") == null)
    {
      iter = proc.getParameters().iterator();
      ClassDeclaration paramStruct = 
	new ClassDeclaration(ClassDeclaration.STRUCT, 
	    paramStructID);

      while(iter.hasNext())
      {
	VariableDeclaration pdecl = ((VariableDeclaration)iter.next());
	if(pdecl.toString().compareTo("void") == 0)
	  continue;

	paramStruct.addDeclaration(pdecl);
      }

      kernelFile.addDeclarationBefore(proc, paramStruct);

      // Create the typedef for terser access
      List typeList = new ChainedList();
      typeList.add(Specifier.TYPEDEF);
      //Shouldn't need a user specifier for this, but it looks like 
      //there isn't another way.
      typeList.add(new UserSpecifier(new Identifier("struct")));

      paramStructType = new UserSpecifier((Identifier)paramStructID.clone());
      typeList.add(paramStructType);

      VariableDeclarator paramTypedef = 
	new VariableDeclarator((Identifier)paramStructID.clone());

      VariableDeclaration paramTypeDecl = 
	new VariableDeclaration(typeList, paramTypedef);

      kernelFile.addDeclarationBefore(proc, paramTypeDecl);
    }

    // Create new interface function body
    CompoundStatement interfaceBody = new CompoundStatement();

    if(Driver.getOptionValue("mcuda_nolib") == null)
    {
      // Instantiate a variable for the parameter structure
      List newParamSpecs = new ChainedList();

      paramStructType = new UserSpecifier((Identifier)paramStructID.clone());
      newParamSpecs.add(paramStructType);
      newParamSpecs.add(PointerSpecifier.UNQUALIFIED);

      VariableDeclarator paramsDeclarator = 
	new VariableDeclarator(MCUDAUtils.getParamsID());


      VariableDeclaration paramsDecl = 
	new VariableDeclaration(newParamSpecs, paramsDeclarator);

      interfaceBody.addDeclaration(paramsDecl);


      //Instantiate a malloc
      List mallocType = new ChainedList();
      paramStructType = new UserSpecifier((Identifier)paramStructID.clone());
      mallocType.add(new UserSpecifier(new Identifier("struct")));
      mallocType.add(paramStructType);

      SizeofExpression mallocArg = 
	new SizeofExpression(mallocType);
      FunctionCall allocation = new FunctionCall(new Identifier("malloc"));
      allocation.addArgument(mallocArg);
      paramStructType = new UserSpecifier((Identifier)paramStructID.clone());
      List specifierList = new ChainedList();
      specifierList.add(paramStructType);
      specifierList.add(PointerSpecifier.UNQUALIFIED);

      Typecast allocTypecast = new Typecast(specifierList, allocation);

      AssignmentExpression assignAlloc = 
	new AssignmentExpression(MCUDAUtils.getParamsID(),
	    AssignmentOperator.NORMAL,
	    allocTypecast);

      ExpressionStatement allocStmt = 
	new ExpressionStatement(assignAlloc);

      interfaceBody.addStatement(allocStmt);
    }
    else {
      //Just create a blockIdx variable, for some for loops
      List<VariableDeclaration> blockIdxDecl = MCUDAUtils.getBidxDecl();

      for(int i = 0; i < blockIdxDecl.size(); i++)
	interfaceBody.addDeclaration(blockIdxDecl.get(i));

      if(Driver.getOptionValue("Xpilot") == null)
      {
	Expression bidz = MCUDAUtils.getBidxID(2);

	AssignmentExpression clearBlockz = 
	  new AssignmentExpression(bidz, 
	      AssignmentOperator.NORMAL,
	      new IntegerLiteral((long)0));

	ExpressionStatement clearZStmt = 
	  new ExpressionStatement(clearBlockz);

	interfaceBody.addStatement(clearZStmt);
      }

    }
      
    //For each parameter, pack it in.
    iter = proc.getParameters().iterator();

    if(Driver.getOptionValue("mcuda_nolib") == null)
    {
      while(iter.hasNext())
      {
	VariableDeclaration pdecl = ((VariableDeclaration)iter.next());
	if(pdecl.toString().compareTo("void") == 0)
	  continue;

	VariableDeclarator pdeclName = 
	  (VariableDeclarator) pdecl.getDeclarator(0);
	Identifier pID = (Identifier) pdeclName.getDirectDeclarator();

	//Assign parameter value to structure
	AccessExpression paramField =
	  new AccessExpression(MCUDAUtils.getParamsID(),
	      AccessOperator.POINTER_ACCESS,
	      pID);

	pID = (Identifier) pdeclName.getDirectDeclarator();

	AssignmentExpression assignParam = 
	  new AssignmentExpression(paramField, AssignmentOperator.NORMAL, pID);

	ExpressionStatement assignParamStmt = 
	  new ExpressionStatement(assignParam);

	interfaceBody.addStatement(assignParamStmt);
      }
    }
    
    //And finally, call the kernel interface
    
    if(Driver.getOptionValue("mcuda_nolib") == null)
    {
      FunctionCall kernelLaunch = 
	new FunctionCall(new Identifier("__mcuda_kernel_launch"));

      kernelLaunch.addArgument(new Identifier(new String(kernelName)));

      List kernelArgs = MCUDAUtils.getGdimID();
      kernelArgs.addAll(MCUDAUtils.getBdimID());

      for(int i = 0; i < kernelArgs.size(); i++)
	kernelLaunch.addArgument((Expression)kernelArgs.get(i));

      UnaryExpression paramAddress = 
	new UnaryExpression(UnaryOperator.ADDRESS_OF, 
	    MCUDAUtils.getParamsID());

      List voidPP = new ChainedList();
      voidPP.add(Specifier.VOID);
      voidPP.add(PointerSpecifier.UNQUALIFIED);
      voidPP.add(PointerSpecifier.UNQUALIFIED);

      Typecast voidPPTypecast = new Typecast(voidPP, paramAddress);

      kernelLaunch.addArgument(voidPPTypecast);

      ExpressionStatement launchStmt = 
	new ExpressionStatement(kernelLaunch);

      interfaceBody.addStatement(launchStmt);
    } 
    else {
      //Create the function call
      FunctionCall kernelCall = 
	new FunctionCall(new Identifier(new String(kernelName)));

      iter = proc.getParameters().iterator();

      while(iter.hasNext())
      {
	VariableDeclaration pdecl = ((VariableDeclaration)iter.next());

	if(pdecl.toString().compareTo("void") == 0)
	  continue;

	VariableDeclarator pDeclarator = 
	  (VariableDeclarator)(pdecl.getDeclarator(0));

	Identifier id = (Identifier) pDeclarator.getDirectDeclarator().clone();

	kernelCall.addArgument(id);
      }
   
      List kernelArgs = MCUDAUtils.getBidxID();
      kernelArgs.addAll(MCUDAUtils.getBdimID());
      kernelArgs.addAll(MCUDAUtils.getGdimID());

      for(int i = 0; i < kernelArgs.size(); i++)
      {
	kernelCall.addArgument((Expression)kernelArgs.get(i));
      }

      //Create body wrappy for kernel call
      ExpressionStatement kernelStmt = 
	new ExpressionStatement(kernelCall);
      
      //Create the outer loop (x index)
      //Init
      Expression assignBidx = 
	new AssignmentExpression(MCUDAUtils.getBidxID(0), AssignmentOperator.NORMAL,
	    				new IntegerLiteral((long)0));

      ExpressionStatement assignBidxStmt = 
				new ExpressionStatement(assignBidx);

      //Comparison
      BinaryExpression BidxComp = 
	new BinaryExpression(MCUDAUtils.getBidxID(0),
	    			BinaryOperator.COMPARE_LT,
				MCUDAUtils.getGdimID(0));

      //Update
      Expression bidxUpdate = 
	new UnaryExpression(UnaryOperator.POST_INCREMENT,
	    			MCUDAUtils.getBidxID(0));

      ForLoop innerLoop = 
	new ForLoop(assignBidxStmt, BidxComp, bidxUpdate, 
	    		kernelStmt);
      
      //Create the outer loop (y index)
      //Init
      assignBidx = 
	new AssignmentExpression(MCUDAUtils.getBidxID(1), AssignmentOperator.NORMAL,
	    				new IntegerLiteral((long)0));

      assignBidxStmt = 
				new ExpressionStatement(assignBidx);

      //Comparison
      BidxComp = 
	new BinaryExpression(MCUDAUtils.getBidxID(1),
	    			BinaryOperator.COMPARE_LT,
				MCUDAUtils.getGdimID(1));

      //Update
      bidxUpdate = 
	new UnaryExpression(UnaryOperator.POST_INCREMENT,
	    			MCUDAUtils.getBidxID(1));

      ForLoop outerLoop = 
	new ForLoop(assignBidxStmt, BidxComp, bidxUpdate,
	    		innerLoop);

      interfaceBody.addStatement(outerLoop);
    }
    
    //Interface function body complete.  We'll swap it for the 
    // current procedure's body at the end.
    

    proc.setBody(interfaceBody);
   
    if(Driver.getOptionValue("mcuda_nolib") == null)
    {
      Statement firstStmt = (Statement)oldbody.getChildren().get(0);
      Declaration firstDecl = null;
      if(firstStmt instanceof DeclarationStatement)
      {
	firstDecl = ((DeclarationStatement)firstStmt).getDeclaration();
      }

      // Add declarations for unpacking the parameters

      //Going to need several copies of the typecasted parameter pointer
      List specifierList = new ChainedList();

      paramStructType = new UserSpecifier((Identifier)paramStructID.clone());
      specifierList.add(paramStructType);
      specifierList.add(PointerSpecifier.UNQUALIFIED);

      Typecast paramsTypecast = 
	new Typecast(specifierList, MCUDAUtils.getParamsID());



      // Loop over parameters
      //List pList = new LinkedList();

      iter = proc.getParameters().iterator();

      while(iter.hasNext())
      {
	VariableDeclaration pdecl = ((VariableDeclaration)iter.next());

	if(pdecl.toString().compareTo("void") == 0)
	  continue;

	VariableDeclaration newDecl = (VariableDeclaration)pdecl.clone();

	// Might be dangerous, but we're going to interpret parameters as 
	// shared data
	newDecl.getSpecifiers().add(0, Specifier.SHARED);

	VariableDeclarator pDeclarator = 
	  (VariableDeclarator)(newDecl.getDeclarator(0));

	Identifier id = (Identifier) pDeclarator.getDirectDeclarator();
	AccessExpression param_access = 
	  new AccessExpression((Expression)paramsTypecast.clone(), 
	      AccessOperator.POINTER_ACCESS, id);

	pDeclarator.setInitializer(new Initializer(param_access));
	//pList.add(pdecl.clone());

	// Add a local variable declaration, and 
	// assign the unpacked parameter to it



	//      AssignmentExpression paramAssignExpr = 
	//	new AssignmentExpression(id, AssignmentOperator.NORMAL, 
	//	    				param_access);

	if(firstDecl == null)
	  oldbody.addDeclaration(newDecl);
	else
	  oldbody.addDeclarationBefore(firstDecl, newDecl);

      }
      //bodywrapper.addStatement(oldbody);
    }

    //Get the parameter list for a kernel function 
    //(runtime implementation specified)
    List kernelParams = MCUDAUtils.getKernelParams();

    if(Driver.getOptionValue("mcuda_nolib") != null)
    {
      Iterator origParams = proc.getParameters().iterator();
      int index = 0;
      while(origParams.hasNext())
      {
	VariableDeclaration pdecl = 
	  (VariableDeclaration)(((VariableDeclaration)(origParams.next())).clone());
	if(pdecl.toString().compareTo("void") == 0)
	  continue;
	kernelParams.add(index, pdecl);
	index++;
      }
    }

    //Declare the new kernel
    ProcedureDeclarator newKernelDecl = 
      new ProcedureDeclarator(new Identifier(new String(kernelName)), 
	  kernelParams);


    //oldbody.addDeclaration(MCUDAUtils.getTidDecl());
    //newbody.addStatement(MCUDAUtils.NewNestedThreadLoop(3, oldbody));

    //Procedure wrapped = 
    //  new Procedure(Specifier.VOID, newKernelDecl, newbody);

    List newKernelSpecs = new ChainedList();
    newKernelSpecs.add(Specifier.GLOBAL);
    newKernelSpecs.add(Specifier.VOID);

    Procedure wrapped = new Procedure(newKernelSpecs, newKernelDecl, oldbody);
    kernelFile.addDeclarationBefore(proc, wrapped);

    //Add the implicit kernel function parameters to the now intermediate 
    // procedure
    List<VariableDeclaration> implicitParams = MCUDAUtils.getGdimDecl();
    implicitParams.addAll(MCUDAUtils.getBdimDecl());

    for(int i = 0; i < implicitParams.size(); i++)
      proc.addDeclaration(implicitParams.get(i));

    //Don't mark the interface function as the kernel anymore
    proc.removeProcedureSpec(Specifier.GLOBAL);
  }

  public void transformPrototype(ProcedureDeclarator proto)
  {
    //Add the implicit kernel function parameters
    List<VariableDeclaration> implicitParams = MCUDAUtils.getGdimDecl();
    implicitParams.addAll(MCUDAUtils.getBdimDecl());

    for(int i = 0; i < implicitParams.size(); i++)
      proto.addParameter(implicitParams.get(i));
  }

}
