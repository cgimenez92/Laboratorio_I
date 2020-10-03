/*
 * is_valid.c
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>

int isValidInt(char*string)
{
	int ret = 1;
	int i = 0;

	for (i = 0 ; string[i] != '\0'; i++)
	{
		if (string[i] > '9' || string[i] < '0')
		{
			ret = 0;
			break;
		}
	}
	return ret;
}

/*
 * esFlotante: Verifica si la cadena ingresada es flotante
 * cadena: cadena de caracteres a ser analizada
 * limite: limite de la cadena
 * Retorno: 1 (verdadero) si la cadena es flotante , 0 (falso) si no y -1 en caso de ERROR de parametro
 *
 */
int isValidFloat(char*string, int limit)
{
	int ret = -1;
	int i = 0;
	int countPoints = 0;

	if(string != NULL && limit > 0)
	{
		ret = 1;
		if(string[0] != '+' || string[0] != '-')
		{
			i = 1;
		}
		while(string[i] != '\0')
		{
			if((string[i] < '0' || string[i] > '9') && string[i] != '.')
			{
				ret = 0;
				break;
			}
			if(string[i] == '.')
			{
				countPoints++;
				if(countPoints > 1)
				{
					ret = 0;
					break;
				}
			}
			i++;
		}
	}
	return ret;
}


int isValidName(char*string, int limit)
{
	int ret = 1;
	int i;

	for (i = 0 ; i<=limit && string[i] != '\0'; i++)
	{
		if	((string[i] < 'a' || string[i] > 'z') &&
			 (string[i] < 'A' || string[i] > 'Z') &&
			  string[i] != '.')
		{
			ret = 0;
			break;
		}
	}
	return ret;
}
