CETUS_HOME = ..

all:
	cd ./base/grammars; $(MAKE)
	javac -classpath $(CETUS_HOME):$(antlr) analysis/*.java exec/*.java hir/*.java transforms/*.java treewalker/*.java base/grammars/*.java

clean:
	@ cd ./base/grammars; $(MAKE) clean
	@ rm -rf */*.class
