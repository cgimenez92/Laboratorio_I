/*
 * array_functions.c
 *
 *  Created on: 28 sep. 2020
 *      Author: cgimenez
 */
#include <stdio.h>
#include <stdlib.h>
#include "array_operations.h"

int printArrayInt(int* pArray, int arraySize)
{
	int ret = -1;

	if(pArray != NULL && arraySize > 0)
	{
		ret = 0;
		for (int i = 0; i < arraySize; i++)
		{
			printf("%d\n", pArray[i]);
		}
	}
	return ret;
}

int sortArrayDsc(int* pArray, int arraySize)
{
	int flagswap;
	int i;
	int count;
	int ret=-1;
	int buffer=0;
	int arrayNotSortSize = arraySize-1;

	if(pArray != NULL && arraySize > 0)
	{
		do
		{
			flagswap = 0;
			for(i=0; i<arrayNotSortSize-1;i++)
			{
				if(pArray[i]<pArray[i+1])
				{
					flagswap = 1;
					swapPostionInArray (pArray, buffer, i);
				}
				count++;
			}
			arrayNotSortSize--;
		} while(flagswap);
		ret=count;
	}
	return ret;
}

int sortArrayAsc(int* pArray, int arraySize)
{
	int flagswap;
	int i;
	int count;
	int ret=-1;
	int buffer=0;
	int arrayNotSortSize = arraySize-1;

	if(pArray != NULL && arraySize > 0)
	{
		do
		{
			flagswap = 0;
			for(i=0; i< arrayNotSortSize ;i++)
			{
				if(pArray[i]>pArray[i+1])
				{
					flagswap = 1;
					swapPostionInArray (pArray, buffer, i);

				}
				count++;
			}
			arrayNotSortSize--;
		} while(flagswap);
		ret=count;
	}
	return ret;
}


int swapPostionInArray (int* pArray, int buffer, int positionToSwap)
{
	int ret = -1;

	if(pArray != NULL && positionToSwap >= 0)
	{
		ret = 0;
		buffer = pArray[positionToSwap];
		pArray[positionToSwap] = pArray[positionToSwap+1];
		pArray[positionToSwap+1] = buffer;
	}

	return ret;
}

///Preguntar de pasar una función por referencia.

//int changeValueInPostionArray (int* pArray, int buffer, int positionToSwap)
//{
//	int ret = -1;
//
//	if(pArray != NULL && positionToSwap >= 0)
//	{
//		ret = 0;
//		buffer = pArray[positionToSwap];
//		pArray[positionToSwap] = pArray[positionToSwap+1];
//		pArray[positionToSwap+1] = buffer;
//	}
//
//	return ret;
//}

int maxIntArray(int* pArray, int arraySize, int* maxValue)
{
	int ret = -1;
	int buffer;
	int i=0;

	if(pArray != NULL && arraySize > 0)
		{
			ret = 0;
			*maxValue = pArray[i];
			for (; i<arraySize; i++)
			{
				buffer = pArray[i];
				 if(buffer > *maxValue)
					 {
					 	 *maxValue = buffer;
					 }
			}
		}
	return ret;
}


int minIntArray(int* pArray, int arraySize, int* minValue)
{
	int ret = -1;
	int buffer;
	int i=0;

	if(pArray != NULL && arraySize > 0)
		{
			ret = 0;
			*minValue = pArray[i];
			for (; i<arraySize; i++)
			{
				buffer = pArray[i];
				 if(buffer < *minValue)
					 {
					 	 *minValue = buffer;
					 }
			}
		}
	return ret;
}

int avgArray(int* pArray, int arraySize, float* avgValue)
{
	int ret = -1;
	int buffer=0;
	int i=0;

	if(pArray != NULL && arraySize > 0)
		{
			ret = 0;
			for (; i<arraySize; i++)
			{
				buffer += pArray[i];
			}
			*avgValue = buffer/arraySize;
		}
	return ret;
}
