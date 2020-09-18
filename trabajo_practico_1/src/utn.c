/*
 * utn.c
 *
 *  Created on: 8 sep. 2020
 *      Author: cgimenez
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getIntWithLimits(char* message, char* firstErrorMessage, char* secondErrorMessage, int* pNumber, int attempts, int min, int max)
{
	int ret = -1;
	int bufferInt;
	int answerScanf;
	if(message != NULL && firstErrorMessage != NULL && secondErrorMessage != NULL && pNumber != NULL && attempts >= 0 && max >= min)
	{
		do
		{
			printf("%s",message);
			fflush(stdin);
			answerScanf = scanf("%d" , &bufferInt);

			if(answerScanf == 1 && bufferInt >= min && bufferInt <= max)
			{
				ret = 0;
				*pNumber = bufferInt;
				break;
			}
			else
			{
				if(answerScanf != 1)
				{
					printf("\n***%s***\n\n",secondErrorMessage);
					attempts--;
					ret= -3;
					continue;
				}

				if(bufferInt < min || bufferInt > max)
				{
					printf("\n***%s***\n\n",firstErrorMessage);
					attempts--;
					ret = -2;
				}
			}

		}while(attempts >= 0);
	}
	return ret;
}



int getFloat(char* message, char* errorMessage, float* pNumber, int attempts)
{
	int ret = -1;
	float bufferInt;
	int answerScanf;

	if(message != NULL && errorMessage != NULL && pNumber != NULL && attempts >= 0)
	{
		do
		{
			printf("\n%s", message);
			fflush(stdin);
			answerScanf = scanf("%f" , &bufferInt);

			if(answerScanf == 1)
			{
				ret = 0;
				*pNumber = bufferInt;
				break;
			}
			else
				{
					printf("\n***%s***\n\n", errorMessage);
					attempts--;
				}
		}while(attempts >= 0);
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
