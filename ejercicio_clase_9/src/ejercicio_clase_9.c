/*
 ============================================================================
 Name        : ejercicio_clase_9.c
 Author      : cgimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LENGHT 50
#define SIZEARRAY 5

typedef struct
	{
		char name[LENGHT];
		int file;
	} Student;

static int myGets(char *cadena, int longitud);
int getIntWithLimits(char* message, char* firstErrorMessage, char* secondErrorMessage, int* pNumber, int attempts, int min, int max);
int esUnNombreValido(char* cadena,int limite);
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int printArray(Student* pArray, int sizeArray);
int getChar(char* message, char* pChar);

int main(void)
{
	setbuf(stdout,NULL);
  	char questionContinue = 'S';
  	int flagOk;
    int option;
	Student arrayStudent[SIZEARRAY];

	for(int i = 0;toupper(questionContinue) == 'S' || option != 4; i++)
	{
		flagOk = getIntWithLimits("\n1- Ingresar Nombre\n2- Ingresar legajo\n3- Imprimir listado estudiantes\n4- Salir\n\nSeleccione una opcion: ",
				"Ingresar una opcion entre [1-4]", "Ingresar un caracter numerico", &option, 3, 1, 4);

		if(!flagOk)
		{
			Student aux;
			switch(option)
			{
			case 1:
				if(!utn_getNombre("Ingrese Nombre: ", "Error ingrese caracteres: ", &aux_name, 3, LENGHT))
				{
					arrayStudent[i].name= aux;
				}
				break;

			case 2:
				if(!getIntWithLimits("Ingrese un Legajo: ", "Ingresar legajo entre [1-5] ", "Ingresar un caracter numerico", &aux.file, 3, 1, 5))
				{
					arrayStudent[i].file= aux;
				}
				break;

			case 3:
				printArray(arrayStudent, SIZEARRAY);
				break;

			case 4:
				printf("\n *** Adios! *** \n");
				questionContinue = 'N';
				break;
			}
		}
		else
			{
				getChar("\n *** Se acabaron los intentos*** \n¿Continuar? - S/N \n", &questionContinue);

				if(toupper(questionContinue) == 'S')
				{
					continue;
				}
				else
					{
						break;
					}
			}
	}

	return EXIT_SUCCESS;
}

static int myGets(char *cadena, int longitud)
{
	fflush(stdin);
	fgets (cadena, longitud, stdin);
	cadena[strlen (cadena) - 1] = '\0';
	return 0;
}

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

int esUnNombreValido(char* cadena,int limite)
{
	int respuesta = 1; // TODO OK
	for(int i=0; i<=limite && cadena[i] != '\0';i++)
	{
		if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] < 'a' || cadena[i] > 'z') &&
			cadena[i] != '.')
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}

int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
	char bufferString[LENGHT];
	int retorno = -1;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LENGHT) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
				esUnNombreValido(bufferString,limite) != 0 )
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int printArray (Student* pArray, int sizeArray)
{
	int ret = -1;

	if(pArray != NULL && sizeArray > 0)
	{
		ret = 0;
		for (int i = 0; i < sizeArray; i++)
		{
			printf("%s - %d\n", pArray[i].name, pArray[i].file);
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
