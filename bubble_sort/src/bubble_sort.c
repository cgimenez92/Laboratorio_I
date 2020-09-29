/*
 ============================================================================
 Name        : bubble_sort.c
 Author      : cgimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define QTY_EMPLOYEES 9

int printArrayInt(int* pArray, int sizeArray);
int sortArrayDsc(int* pArray, int arraySize);
int sortArrayAsc(int* pArray, int arraySize);
int swapPostionInArray (int* pArray, int buffer, int positionToSwap);

int main(void)
{
	int age_employees[QTY_EMPLOYEES] = {54,26,93,17,77,31,44,55,27};
	int answer;

	printArrayInt(age_employees, QTY_EMPLOYEES);
	answer = sortArrayDsc(age_employees, QTY_EMPLOYEES);
	if(answer>0)
	{
		printf("\nIteraciones: %d\n", answer);
	}

	printf("\n\n");
	printArrayInt(age_employees, QTY_EMPLOYEES);
	return EXIT_SUCCESS;
}

int printArrayInt(int* pArray, int sizeArray)
{
	int ret = -1;

	if(pArray != NULL && sizeArray > 0)
	{
		ret = 0;
		for (int i = 0; i < sizeArray; i++)
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

