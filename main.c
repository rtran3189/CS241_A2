/*	Name: Richard Tran
 * 	Date: January 10, 2019
 * 	Class: CS241L SUM 2019
 *
 *	This file contains the main function for the entire program.
 *	Also contains functions relating to parsing the arguments when
 *	running the program.
 */

#include <stdio.h>
#include <limits.h>
#include "opera.h"
#include "help.h"

#define ASSIGNMENT_NUMBER 2


/*
 * This function checks if a specified flag exists in the arguments.
 * Returns 1 (True) if found, otherwise 0 (False).
 */
int checkForSpecificFlag(int argc, char ** argv, char c)
{
	int i = 0;
	int j = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			j = 0;
			while(argv[i][j])
			{
				if (argv[i][j] == c)
				{
					return 1;
				}
				j++;
			}
		}
		i++;
	}
	return 0;
}

/*
 *	Gets passed argc (# of arguments) and argv (the arguments themselves).
 * 	The number of arguments determines what operation to take (4 is Bitwise Not or
 *	change of base) and 6 is Arithmetic or Bitwise Operations.
 */
void parseArguments(int argc, char ** argv)
{
	/*
	 * Checks if there are SIX (+1 since ./a.out) arguments, which fits
	 * arithmetic/bitwise operations.
	 */
	if (argc == 7)
	{
		int arithmeticResult = 0;
		int counter = 1;
		int leftArgument = convertIn(argv[2], argv[1][1]);
		int rightArgument = convertIn(argv[5], argv[4][1]);

		arithmeticResult = arithmetic(leftArgument, argv[3][1], rightArgument);

		if ((arithmeticResult >= 0) && (arithmeticResult <= SHRT_MAX))
		{
			while(argv[6][counter])
			{
				convertOut(argv, arithmeticResult, argv[6][counter]);
				counter++;
			}
		}
		else
		{
			printError(1);
		}

	}

	/*
	 * Checks if there are FOUR (+1 since ./a.out) arguments, which fits
	 * bitwise/change of base operations.
	 */
	else if (argc == 5)
	{
		/* Sends num1 and the input base for num1 to convert to decimal
	   	for processing. */
		int convertToDecimal = convertIn(argv[2], argv[1][1]);
		int counter = 0;

		if((convertToDecimal >= 0) && (convertToDecimal <= SHRT_MAX))
		{
			if (checkForSpecificFlag(argc, argv, 'c'))
			{
				printf("Performing change of base.\n");
				while(argv[4][counter])
				{
					convertOut(argv, convertToDecimal, argv[4][counter]);
					counter++;
				}
			}

			else if (checkForSpecificFlag(argc, argv, 'n'))
			{	
				int convertToNot = (~convertToDecimal);
				printf("Performing bitwise not.\n");
				while(argv[4][counter])
				{
					convertOut(argv, convertToNot, argv[4][counter]);
					counter++;
				}


			}
		}
		else
		{
			printError(1);
		}

		
	}
	else
	{
		/* Prints "Invalid number of arguments" error. */
		printError(0);
	}
}

/*
 *	Main function that drives the entire program.
 */
int main (int argc, char **argv)
{
	checkForPrintFlag(argc, argv, ASSIGNMENT_NUMBER);
	parseArguments(argc, argv);

	return 0; 
}
