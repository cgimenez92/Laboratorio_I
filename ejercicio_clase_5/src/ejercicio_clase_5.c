/*
 ============================================================================
 Name        : ejercicio_clase_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define LENGHT_ARRAY 5

int calcMax(int* pArray, int qtyElements, int* pResultado);

int main(void)
{
	setbuf(stdout,NULL);
	int answerNumber;
	int attempts = 5;
	int arrayInt[LENGHT_ARRAY];
	int flagCorrectAnswer = 0;
	int maximo;

	for (int i=0 ; i<LENGHT_ARRAY ; i++)
	{
		if(getIntWithLimits ("Numero\n", "Ingresa un caracter numerico", &answerNumber, 0, 1000, attempts) != 0)
		{
			printf("Error");
			flagCorrectAnswer = -1;
			break;
		}
		else
		{
			arrayInt[i] = answerNumber;
		}
	}

	if (flagCorrectAnswer ==0)
	{
		if (calcMax(arrayInt, LENGHT_ARRAY, &maximo)==0)
		{
			printf ("maximo = %d", maximo);

		}
		else
		{
			printf ("Error");
		}

	}

	return EXIT_SUCCESS;
}



int calcMax(int* pArray, int qtyElements, int* pResultado)
{
	int ret;
	int maximo;
	if (pArray != NULL && qtyElements > 0 && pResultado != NULL)
	{
		for (int i=0; i<qtyElements; i++)
		{
			if(i==0 || pArray[i] > maximo)
			{
				maximo = pArray[i];
			}

		}
		*pResultado = maximo;
		ret = 0;
	}
	return ret;
}

