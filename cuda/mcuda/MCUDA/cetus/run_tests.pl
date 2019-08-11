#!/usr/bin/perl
#
# Cetus Test Suite
# by Troy A. Johnson
#
# Directions
# ----------
# 1) Place a source file in tests/inputs. This will be the input of the test.
#    For example, you would create tests/inputs/main.c
# 2) Place a source file in tests/solutions. This will be the expected result.
#    For example, you would create tests/solutions/main.c
# 3) Create a test configuration file in tests/.  A sample config file
#    is below.
#
# Sample config file
#
# ------cut here------
# #This is a comment in the config file
# input is main.c
# solution is main.c
# command is -tsingle-return
# ------cut here------
#
# This script will run Cetus on the input using the command, and check
# the output against the solution using diff.  If the diff is empty, the
# test is reported to be PASSED, otherwise the test has FAILED.
#
# Note the input and the solution must be a single file name.  The file
# names do not have to be the same.  The command can be empty.  The "is"
# is treated as a keyword and must have a single space before and after.

# for every config file in tests/ ...
while (defined($filename = glob("tests/*.cfg")))
{
  # open the config file
  open(CONFIG, $filename) || die "can't open $filename: $!";

  # conf is an associative array that represents values in the config file
  my(%conf);

  # setup the conf array by reading the config file, and ignore comments
  while ($line = <CONFIG>)
  {
    chomp($line);
    if (substr($line, 0, 1) ne "#")
    {
      @s = split(/ is /, $line);
      $conf{$s[0]} = $s[1];
    }
  }

  # run Cetus and put the output in tests/outputs
  system "java -classpath ..:antlr.jar cetus.exec.Driver -antlr -outdir=tests/outputs "
         . $conf{"command"} . " tests/inputs/" . $conf{"input"};

  # diff the output and the solution
  if (system("diff -y --suppress-common-lines tests/outputs/" . $conf{"input"} . " tests/solutions/" . $conf{"solution"}) == 0)
  {
    print "PASSED $filename\n";
  }
  else
  {
    print "FAILED $filename\n";
  }

  system("mv tests/outputs/" . $conf{"input"} . " tests/outputs/" . $conf{"solution"} . ".result");
}
