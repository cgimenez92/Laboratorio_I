/*
 * gets.c
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
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
	if (!myGets(buffer,sizeof(buffer)) && isValidInt(buffer))
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

static int getArrayChar(char* pResult)
{
	int ret = -1;
	char buffer[BUFFER_SIZE];
	if (!myGets(buffer,sizeof(buffer)))
	{
		strncpy(pResult,buffer,sizeof(buffer)-1);
		ret = 0;
	}
	return ret;
}

int getYesOrNo(char* message, char* firstErrorMessage, char* secondErrorMessage, char* pChar, int attempts, int stringSize)
{
	int ret = -1;
	char bufferChar[BUFFER_SIZE];

	if(message != NULL && pChar != NULL)
	{
		do
		{
			printf("%s\n",message);
			if( !myGets(bufferChar, sizeof(bufferChar)) &&
				!strnicmp(bufferChar, "S", stringSize))
			{
				ret = 0;
				strncpy(pChar,bufferChar,stringSize);
				break;
			}
			else if(!strnicmp(bufferChar,"N", stringSize))
				{
					printf("%s\n",firstErrorMessage);
					ret = -2;
					break;
				}
				else
				{
					printf("%s\n",secondErrorMessage);
					attempts--;
				}
		}while(attempts >= 0);
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

int getCuit(char* message, char* firstErrorMessage, char* secondErrorMessage, char* pResult, int attempts, int stringSize)
{
	char buffer[BUFFER_SIZE];
	int ret = -1;

	if(	message != NULL &&
		firstErrorMessage != NULL &&
		secondErrorMessage != NULL &&
		pResult != NULL &&
		attempts >= 0 &&
		stringSize > 0)
	{
		do
		{
			printf("%s\n",message);
			if( !myGets(buffer,stringSize) &&
				strnlen(buffer,sizeof(buffer)-1) <= stringSize &&
				isValidCuit(buffer,stringSize)>0)
			{
				strncpy(pResult,buffer,stringSize);
				ret = 0;
				break;
			}
			else
			{
                if (isValidCuit(buffer,stringSize)== -1)
                {
                    printf("%s\n", firstErrorMessage);
                }

                if (isValidCuit(buffer,stringSize)== -2)
                {
                    printf("%s\n", secondErrorMessage);
                }
                attempts--;
			}
		}while(attempts >= 0);

	}
	return ret;
}

int getString(char* message, char* errorMessageLenght, char* pResult, int attempts, int stringSize)
{
    int ret=-1;
    char buffer[BUFFER_SIZE];

	if(	message != NULL &&
		errorMessageLenght != NULL &&
		pResult != NULL &&
		attempts >= 0 &&
		stringSize > 0)
	{
		do
		{
			printf("%s\n", message);
			if(!getArrayChar(buffer) && strnlen(buffer, stringSize))
			{
				strncpy(pResult,buffer,stringSize);
				ret = 0;
				break;
			}
			else
			{
				if(strlen(buffer)>stringSize)
				{
					printf ("%s\n", errorMessageLenght);
				}
				attempts--;
			}
		}while(attempts >= 0);
	}
    return ret;
}





