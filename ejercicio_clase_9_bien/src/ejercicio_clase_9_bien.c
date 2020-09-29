/*
 ============================================================================
 Name        : ejercicio_clase_9_bien.c
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
#define TRUE 1
#define FALSE 0

typedef struct
{
	char name[LENGHT];
	int file;
	int isEmpty;
} Student;

int createStudent(Student* pArrayStudent, int sizeArray, int index);

int createStudent(Student* pArrayStudent, int sizeArray, int index)
{
	int ret = -1;
	Student bufferStudent;
	if(pArrayStudent != NULL && sizeArray >= 0 && index < sizeArray)
	{
		if(!utn_getInt() &&
			!utn_getNombre() //getFile o getLegajo--> Generar la funcion )
		{
			pArrayStudent[index] = bufferStudent;
			pArrayStudent[index].isEmpty = FALSE;
		}
	}
	return ret;
}

int printStudent(Student* pArrayStudent, int sizeArray)
{
	int ret = -1;

	if(pArrayStudent != NULL && sizeArray > 0)
	{
		ret = 0;
		for (int i = 0; i < sizeArray; i++)
		{
			if(pArrayStudent[i].isEmpty == FALSE)
				{
					printf("%s - %d\n", pArrayStudent[i].name, pArrayStudent[i].file);
				}
		}
	}
	return ret;
}



int initStudent(Student* pArrayStudent, int sizeArray)
{
	int ret = -1;

	if(pArrayStudent != NULL && sizeArray > 0)
	{
		ret = 0;
		for (int i = 0; i < sizeArray; i++)
		{
			pArrayStudent[i].isEmpty = TRUE;
		}
	}
	return ret;
}

int main(void)
{
	setbuf(stdout,NULL);
  	char questionContinue = 'S';
  	int flagOk;
    int option;
    int index;
	Student arrayStudent[SIZEARRAY];

	initStudent(arrayStudent, SIZEARRAY);

	do
	{

		getIntWithLimits("\n1- Ingresar Nombre\n2- Ingresar legajo\n3- Imprimir listado estudiantes\n4- Salir\n\nSeleccione una opcion: ",
						"Ingresar una opcion entre [1-4]", "Ingresar un caracter numerico", &option, 3, 1, 4);
		Student aux;

		switch(option)
		{
		case 1:
			if(!getIntWithLimits("\nIndice?","Ingresar una opcion entre [1-4]", "Ingresar un caracter numerico", &option, 3, 1, 4))
			{
				createStudent(arrayStudent, SIZEARRAY, index);
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

	}while(option!=4);

	return EXIT_SUCCESS;
}


