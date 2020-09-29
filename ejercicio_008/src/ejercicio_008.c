/*
 ============================================================================
 Name        : ejercicio_008.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "get.h"
#include "array_functions.h"
#define ARRAY_SIZE 5

int main(void)
{
	setbuf(stdout,NULL);

	int number;
	int i;
	int arrayInt[ARRAY_SIZE];
	int max;
	int min;
	int flagOk;
	int option;
	int arrayIndex;
	float avg;
  	char questionContinue = 'N';

	for(i=0; i<ARRAY_SIZE; i++)
	{
		if(!getInt ("Ingrese un número: \n", "Error - Ingresar un caracter númerico \n", &number, 3))
		{
			arrayInt[i] = number;
		}
	}

    do
    {
		flagOk = getIntWithLimits("\n1- Mostrar Array\n2- Modificar valor en array \n3- Mostrar resultados (Min-Max-Promedio)\n4- Salir\n\nSeleccione una opcion: ",
									"\nIngresar un caracter numerico", &option, 1, 4, 3);

		if(!flagOk)
		{
			switch(option)
			{
			case 1:
				printArrayInt(arrayInt, ARRAY_SIZE);
				break;

			case 2:
				if(!getIntWithLimits("\nIngresar Indice a modificar: ", "Ingresar un caracter numerico", &arrayIndex, 0, 4, 3))
				{
					if(!getInt ("Ingrese un número: \n", "Error - Ingresar un caracter númerico \n", &number, 3))
					{
						arrayInt[arrayIndex] = number;
					}
				}
				else
				{

					printf ("Error\n");
				}
				break;

			case 3:

				if(!minIntArray(arrayInt, ARRAY_SIZE, &min))
				{
					printf("min: %d\n", min);
				}

				if(!maxIntArray(arrayInt, ARRAY_SIZE, &max))
				{
					printf("max: %d\n", max);
				}

				if(!avgArray(arrayInt, ARRAY_SIZE, &avg))
				{
					printf("promedio: %f \n", avg);
				}
				break;

			case 4:
				printf("\n *** Adios! *** \n");
				questionContinue = 'N';
				break;
			}
		}
		else
			{
				getChar("\n *** Se acabaron los intentos, volver a ejecutar programa *** \n¿Continuar? - S/N \n", &questionContinue);

				if(toupper(questionContinue) == 'S')
				{
					continue;
				}
				else
					{
						break;
					}
			}

    } while(toupper(questionContinue) == 'S' || option != 4);

	return EXIT_SUCCESS;
}
