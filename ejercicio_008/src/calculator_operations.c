/*
 * calculator_operations.c
 *
 *  Created on: 8 sep. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>

int sumOperation(float firstOperator, float secondOperator, float* pResult)
{
	int ret = -1;

	if(pResult != NULL)
	{
		*pResult = firstOperator + secondOperator;
		ret = 0;
	}
	else
	{
		ret = -1;
	}

return ret;
}

int restOperation(float firstOperator, float secondOperator, float* pResult)
{
	int ret = -1;

	if(pResult != NULL)
	{
		*pResult = firstOperator - secondOperator;
		ret = 0;
	}

return ret;
}


int divideOperation(float firstOperator, float secondOperator, float* pResult)
{
	int ret = -1;

	if (pResult != NULL && secondOperator != 0)
	{
		*pResult = firstOperator / secondOperator;
		ret =0;
	}

	return ret;
}


int multiplyOperation(float firstOperator, float secondOperator, float* pResult)
{
	int ret = -1;

	if(pResult != NULL)
	{
		*pResult = firstOperator * secondOperator;
		ret = 0;
	}

return ret;
}
