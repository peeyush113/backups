classfiles = LineObject.class PreprocessorInfoChannel.class CToken.class PreCParser.class PreCLexer.class PreCParserTokenTypes.class NewCParser.class NewCLexer.class NEWCTokenTypes.class  MyReader.class Pragma.class

javafiles = CToken.java LineObject.java PreprocessorInfoChannel.java NewCParser.java NewCLexer.java NEWCTokenTypes.java PreCParser.java PreCLexer.java PreCParserTokenTypes.java MyReader.java Pragma.java

classpath = $(antlr):../../..

all : $(javafiles) $(classfiles)

clean : 
	@ rm -rf *.class NewCLexer.java NewCParser.java NEWCTokenTypes.java NEWCTokenTypes.txt PreCLexer.java PreCParser.java PreCParserTokenTypes.java PreCParserTokenTypes.txt

PreCParser.java PreCLexer.java : Pre.g
	java -classpath $(classpath) antlr.Tool Pre.g

NewCParser.java NewCLexer.java : NewCParser.g
	java -classpath $(classpath) antlr.Tool NewCParser.g

.SUFFIXES: .java .class

.java.class : 
	javac -classpath $(classpath) -deprecation $<
