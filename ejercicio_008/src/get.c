/*
 * get.c
 *
 *  Created on: 8 sep. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>


int getFloat (char* pMessage, char* pErrorMessage, float* pNumber, int attempts)
{
	int ret = -1;
	float bufferFloat;
	int answerScanf;

	if (pMessage != NULL && pErrorMessage != NULL && pNumber != NULL)
	{
		printf(pMessage);
		fflush(stdin);
		answerScanf = scanf("%f",&bufferFloat);

		while (attempts>=0)
		{
			if (answerScanf == 1)
			{

				attempts--;
				printf(pErrorMessage);

				if(attempts==0)
					{
						ret = -2;
					}
			}
			else
				{
					*pNumber = bufferFloat;
					ret = 0;
					break;
				}
		}
	}

	return ret;
}


int getInt(char* message, char* errorMessage, int* pNumber, int attempts)
{
	int ret = -1;
	int bufferInt;
	int answerScanf;
	if(message != NULL && errorMessage != NULL && pNumber != NULL && attempts >= 0)
	{
		do
		{
			printf("%s",message);
			fflush(stdin);
			answerScanf = scanf("%d" , &bufferInt);

			if(answerScanf == 1)
			{
				ret = 0;
				*pNumber = bufferInt;
				break;
			}
			else
			{
				if(answerScanf != 1)
				{
					printf("\n***%s***\n\n",errorMessage);
					attempts--;
					ret= -2;
					continue;
				}
			}

		}while(attempts >= 0);
	}
	return ret;
}

int getOperation (char* pMessage, char* pErrorMessage, char* pOperation, int attempts)
{
	int ret = 0;

	printf(pMessage);
	fflush(stdin);
	scanf("%c", pOperation);

	while(attempts >= 0 && (*pOperation != '+' && *pOperation != '-' && *pOperation != '/' && *pOperation != '*'))
		{
			printf(pErrorMessage);
			fflush(stdin);
			scanf("%c", pOperation);
			attempts--;

			if(attempts==0)
			{
				ret = -1;
			}
		}
	return ret;
}

int getIntWithLimits (char* pMessage, char* pErrorMessage, int* pNumber, int min, int max, int attempts)
{
	int ret = -1;
	int bufferInt;
	int answerScanf;

	if (pMessage != NULL && pErrorMessage != NULL && pNumber != NULL && min <= max)
	{
		printf(pMessage);
		fflush(stdin);
		answerScanf = scanf("%d",&bufferInt);

		while (attempts >= 0)
		{
			if (answerScanf != 1) //// Verificar el maximo y el minimo.
 			{
				if(bufferInt >= min && bufferInt <= max)
				{
					break;
				}

				if(attempts==0)
				{
					ret = -2;
				}

				attempts--;
				printf(pErrorMessage);
			}
			else
				{
					*pNumber = bufferInt;
					ret = 0;
					break;
				}
		}
	}

	return ret;
}

int getChar(char* message, char* pChar)
{
	int ret = -1;
	char bufferChar;

	if(message != NULL && pChar != NULL)
	{
		printf("\n%s", message);
		fflush(stdin);
		scanf("%s" , &bufferChar);
		*pChar = bufferChar;
		ret = 0;
	}
	return ret;
}

