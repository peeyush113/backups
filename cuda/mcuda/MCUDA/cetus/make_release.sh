#!/bin/sh

antlr=/home/yara/re/paramnt/tools/antlr-2.7.5/antlr-2.7.5.jar

#Compile everything
echo Compiling
make antlr=$antlr

#Make the javadoc documentation
echo Making javadoc
env CLASSPATH=$PWD/..:$antlr ./run_javadoc.sh
echo Compressing javadoc
tar czf ../docs.tar.gz javadocs
rm -rf javadocs

#Make the docbook manual
cd manual
echo Making docbook
./makedoc.sh
echo Compressing docbook
tar czf ../../manual.tar.gz html
rm -rf html
cd ..

#Do everything else from the parent directory
cd ..
jar -cvf cetus.jar cetus/analysis/*.class cetus/base cetus/exec/*.class cetus/hir/*.class cetus/transforms/*.class cetus/treewalker/*.class

rm cetus/analysis/*.class cetus/base/grammars/*.class cetus/exec/*.class cetus/hir/*.class cetus/transforms/*.class cetus/treewalker/*.class

tar -X cetus/Xlist -czf cetus.tar.gz cetus.jar cetus
