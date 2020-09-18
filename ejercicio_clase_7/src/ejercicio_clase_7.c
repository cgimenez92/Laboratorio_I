/*
 ============================================================================
 Name        : ejercicio_clase_7.c
 Author      : cgimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define LENGHT_NAME 51

// (getName(char* menssage, char* messageEroor, char* pResult, int attemtps, int limite)) Pedir nombre con scanf, verificar el limite (strlen - usar reintento)
// y chequear que cada uno de los caracteres de ese array sea una letra (preguntar si lo que esta en el a-z y A-Z) is hay espacio esta mal
{
	char bufferInt[4096];


}


int main(void)
{
	char nombre[LENGHT_NAME] = "JUAN"; // Es capaz de guardar 50 caracteres.
	char nombre2[LENGHT_NAME] = "PEPE";
	char varstring[LENGHT_NAME];
	int resultadoCmp;

	strncpy(nombre,nombre2,sizeof(nombre)-1); //nombre = nombre2 // MAL; --> sizeof-1 (q letras que soporta la variable ) estalbece un limite al array a copiar, no desborda variable.

	resultadoCmp = strnicmp(nombre,nombre2, sizeof(nombre)-1);
	if(!resultadoCmp)
	{
		printf("son iguales");
	}
	else if (resultadoCmp > 0)
	{
		printf("el primer nombre es mas grande");
	}
	else
	{
		printf("el segundo nombre es mas grande");
	}

	strnlen(nombre, LENGHT_NAME-1); // -1 por que el último caracter esta definido para el \0
	snprintf(varstring, LENGHT_NAME-1, "%fhola%d%s", 2.22, 10, "HOLA");// 1° parametro donde quiero guardar, 2° lo que quiero imprimir, 3° --> estas armando una variable, luego se la imprime
	printf("%s", varstring);


	return EXIT_SUCCESS;
}




/////////////////////////////////////////////////////////////////////////////////////////

int isValidName(char* str, int limit)
{
	int answer = 1;

	for(int i=0; i <= limit && str[i] != '\0'; i++)
	{
		if((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') && str[i] = ' ')
		{
			answer = 0;
			break;
		}
	}
	return answer;
}


static int myGets (char *str, int longitud) //static funcion privada, unicamente dentro del archivo
{
  fflush (stdin);
  fgets (str, longitud, stdin);
  str[strlen (str) - 1] = '\0';

  return 0;
}

int getName(char* message, char* messageError, char* pResult, int attemtps, int limit)
{
	char bufferString [4096]; //define del limite bufferstring;

	if(message != NULL && messageError != NULL && pResult != NULL && attemtps >= 0 && limit > 0)
	{
		do
		{
			printf("\n%s", message);
			myGets(bufferString, 4096); //define del limite bufferstring;

			if(myGets(bufferString, 4096) == 0&&
				strlen(bufferString)	)
			{
				ret = 0;
				*pResult = bufferInt;
				break;
			}
			else
				{
					printf("\n***%s***\n\n", messageError);
					attemtps--;
				}
		}while(attempts >= 0);
	}
	return ret;
}


// funcion getstring (bajo nivel) --> getName se agrega la validacion -->

