Name: Richard Tran
Assignment: 2
Course: CS241L Summer 2019
Date: June 10 2019

Directory: Top
Compile Command: gcc -Wall -pedantic -ansi main.c help.c opera.c
Run Command: ./a.out <SEE BELOW FOR INSTRUCTIONS>
Running Test: N/A
Bugs:
	- Does not do well with negative numbers since I was not able to come up with a solution to handle that in time. This includes negative numbers in the input as well as some cases for the output.
	- Due to the way I handled parsing argument options, there isn't a way to do calculations as well as printing the -a or -h (or both -ah/-ha) commands. A calculation must be done without the -a or -h commands because it counts the number of arguments to perform different operations. For example, ./a.out -d 32766 -+ -d 1 -dbx -ha will not work because the -ha at the end will increase the expected number of arguments for arithmetic operations. It will print the help and author message, but will not perform the arithmetic operation.
 
-----------INSTRUCTIONS-----------
To perform arithmetic or bitwise operations (except NOT):
         Six (6) arguments need to be supplied and in this format:
         -<input base> num1 -operation -<input base> num2 -<output base>
         Example: -d 14 -+ -b 11 -x
                will add 14 (base 10) and 11 (base 2) and print the result in hex.

         NOTE: When performing any logical operators (|, &, ^, <, >)
         You MUST escape the operator with '\' before the operator itself.
         Example: -d 14 -\& -b 11 -x

To perform Bitwise Not:
         Four (4) arguments need to be supplied and in this format:
         -<input base> num -n -<output base>
         Example: -o 11 -n -d
                 will perform bitwise not on 11 (base 8) and outputs the answer in base 10.

To perform Change Base:
         Four (4) arguments need to be supplied and in this format:
         -<input base> operand -c -<output base>
         Example: -x AB -c -o
                 will convert AB (base 16) and outputs the answer in base 8.

 Multiple output formats can be chained at the end to output into different bases.
        Example: -b 1111 -+ -x F -dbxo
                 will output the solution in all four bases.

 Valid Numerical Base Designations:
         -b : binary      (base 2)
         -d : decimal     (base 10)
         -o : octal       (base 8)
         -x : hexidecimal (base 16)



SAMPLE INPUT AND OUTPUTS:

./a.out -d 32766 -+ -d 1 -dbx
Converted to decimal: 32767
Converted to binary: 111111111111111
Converted to hexadecimal: 0x7FFF

./a.out -x F -/ -d 3 -b
Converted to binary: 101

./a.out -b 10010101 -c -do
Performing change of base.
Converted to decimal: 149
Converted to octal: O225

./a.out -o 256 -c -bd
Performing change of base.
Converted to binary: 10101110
Converted to decimal: 174