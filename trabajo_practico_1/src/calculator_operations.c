/*
 * calculator_operations.c
 *
 *  Created on: 8 sep. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>

int fSumOperation(float firstOperator, float secondOperator, float* pResult)
{
	int ret = -1;

	if(pResult != NULL)
	{
		*pResult = firstOperator + secondOperator;
		ret = 0;
	}

return ret;
}

int fRestOperation(float firstOperator, float secondOperator, float* pResult)
{
	int ret = -1;

	if(pResult != NULL)
	{
		*pResult = firstOperator - secondOperator;
		ret = 0;
	}

return ret;
}


int fDivideOperation(float firstOperator, float secondOperator, float* pResult)
{
	int ret = -1;

	if (pResult != NULL && secondOperator != 0)
	{
		*pResult = firstOperator / secondOperator;
		ret =0;
	}

	return ret;
}


int fMultiplyOperation(float firstOperator, float secondOperator, float* pResult)
{
	int ret = -1;

	if(pResult != NULL)
	{
		*pResult = firstOperator * secondOperator;
		ret = 0;
	}

return ret;
}


int fFactorial(float firstOperator, float secondOperator, unsigned long int* pResultFirstOperator, unsigned long int* pResultSecondOperator)
{
	int ret = -1;

	if(pResultFirstOperator != NULL && pResultSecondOperator != NULL && firstOperator >= 0 && secondOperator >= 0)
	{
		for(*pResultFirstOperator=1; firstOperator>0; firstOperator--)
			{
				*pResultFirstOperator = (unsigned long int)*pResultFirstOperator * ((unsigned long int)firstOperator);
			}

		for(*pResultSecondOperator=1; secondOperator>0; secondOperator--)
			{
				*pResultSecondOperator = (unsigned long int)*pResultSecondOperator * ((unsigned long int)secondOperator);
			}
		ret = 0;
	}
	else
		{
			if(firstOperator < 0)
			{
				ret = -2;
			}

			if(secondOperator < 0)
			{
				ret = -3;
			}
		}

	return ret;
}

