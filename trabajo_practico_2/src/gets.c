/*
 * gets.c
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "is_valid.h"
#define BUFFER_SIZE 4096

static int myGets(char* string, int arraySize);
static int getCharToInt (int* pResult);
static int getCharToFloat (float* pResult);

static int myGets(char* string, int arraySize)
{
	fflush(stdin);
	fgets (string, arraySize, stdin);
	string[strlen (string) - 1] = '\0';
	return 0;
}

static int getCharToInt (int* pResult)
{
	int ret = -1 ;
	char buffer[BUFFER_SIZE];
	if (!myGets(buffer,sizeof(buffer)) && isValidInt(buffer)== 1)
	{
		ret = 0;
		*pResult = atoi(buffer);
	}
	return ret;
}

static int getCharToFloat (float* pResult)
{
	int ret = -1 ;
	char buffer[BUFFER_SIZE];
	if (!myGets(buffer,sizeof(buffer)) && isValidFloat(buffer,sizeof(buffer)))
	{
		*pResult = atof(buffer);
		ret = 0;
	}
	return ret;
}

int getName(char* message, char* errorMessage, char* pResult, int attempts, int stringSize)
{
	char buffer[BUFFER_SIZE];
	int ret = -1;

	if(	message != NULL &&
		errorMessage != NULL &&
		pResult != NULL &&
		attempts >= 0 &&
		stringSize > 0)
	{
		do
		{
			printf("%s\n",message);
			if( !myGets(buffer,BUFFER_SIZE) &&
				strnlen(buffer,sizeof(buffer)-1) <= stringSize &&
				isValidName(buffer,stringSize) != 0)
			{
				ret = 0;
				strncpy(pResult,buffer,stringSize);
				break;
			}
			else
			{
				printf("%s\n",errorMessage);
				attempts--;
			}
		}while(attempts >= 0);

	}
	return ret;
}

int getInt(char* message, char* errorMessage, int* pResult, int attempts, int min, int max)
{
	int ret = -1;
	int buffer;

	if( message != NULL &&
		errorMessage != NULL &&
		pResult != NULL &&
		attempts >= 0 &&
		max >= min)
	{
		do
		{
			printf("%s\n",message);
			fflush(stdin);
			if(!getCharToInt(&buffer) && buffer >= min && buffer <= max)
			{
				ret = 0;
				*pResult = buffer;
				break;
			}
			else
			{
				printf("%s\n",errorMessage);
				attempts--;
			}
		}while(attempts >= 0);
	}
	return ret;
}

int getFloat (char* message, char* errorMessage, float* pResult, int attempts, float min, float max)
{

	int ret = -1;
	float buffer;
	if (pResult != NULL && message != NULL && errorMessage != NULL && max>min && attempts>=0) {
	do
	{
		printf("%s\n", message);
		fflush(stdin);
		if (!getCharToFloat(&buffer) && buffer >= min && buffer <= max)
		{
			*pResult = buffer;
			ret = 0;
			break;
		}
		else
		{
			printf("%s\n", errorMessage);
			attempts--;
		}
	} while (attempts >= 0 );

	}
	return ret;
}


int getOperation(char* message, char* errorMessage, char* operation, int attempts)
{
	int ret = 0;

	printf(message);
	fflush(stdin);
	scanf("%c", operation);

	while(attempts >= 0 && (*operation != '+' && *operation != '-' && *operation != '/' && *operation != '*'))
		{
			printf(errorMessage);
			fflush(stdin);
			scanf("%c", operation);
			attempts--;

			if(attempts==0)
			{
				ret = -1;
			}
		}
	return ret;
}
