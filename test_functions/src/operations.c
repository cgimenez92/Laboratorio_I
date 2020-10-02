/*
 * operations.c
 *
 *  Created on: 1 oct. 2020
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


int fFactorialOperation(float firstOperator, float secondOperator, unsigned long int* pResultFirstOperator, unsigned long int* pResultSecondOperator)
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

int fMaxValue(float* pArray, float* pMaxValue, int arraySize)
{
	int ret = -1;
	int buffer;
	int i=0;

	if(pArray != NULL && arraySize > 0)
		{
			ret = 0;
			*pMaxValue = pArray[i];
			for (; i<arraySize; i++)
			{
				buffer = pArray[i];
				 if(buffer > *pMaxValue)
				 {
					 *pMaxValue = buffer;
				 }
			}
		}
	return ret;
}

int fMinValue(float* pArray, float* pMinValue, int arraySize)
{
	int ret = -1;
	int buffer;
	int i=0;

	if(pArray != NULL && arraySize > 0)
		{
			ret = 0;
			*pMinValue = pArray[i];
			for (; i<arraySize; i++)
			{
				buffer = pArray[i];
				 if(buffer < *pMinValue)
				 {
					 *pMinValue = buffer;
				 }
			}
		}
	return ret;
}

int fAvgValue(float* pArray, float* pResultAvg, int arraySize)
{
	int ret;
	float buffer=0;
	int i;

	if (pArray!=NULL && pResultAvg!=NULL && arraySize>0)
	{
		for(i=0;i<arraySize;i++)
		{
			buffer += pArray[i];
		}

		*pResultAvg=buffer/arraySize;
		ret=0;
	}

	return ret;
}
