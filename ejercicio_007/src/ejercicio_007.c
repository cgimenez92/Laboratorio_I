/*
 ============================================================================
 Name        : ejercicio_007.c
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

int main(void)
{
	setbuf(stdout,NULL);
	int answerNumber, randomNumber;
	char stillPlay = 's';
	int attempts=2;

	randomNumber = rand() % 101;
	printf("%d", randomNumber);

	do
	{
		if(getIntWithLimits ("Ingresa un numero entre 0 y 100", "Ingresa un caracter numerico", &answerNumber, 0, 100, attempts) == 0)
		{
			if(answerNumber < 0)
			{
				printf ("Ingresaste  un número negativo se termina el juego");
				continue;
			}

			if(answerNumber < randomNumber)
			{
				printf ("El numero ingresado es menor al numero de oro");
				attempts++;
				continue;
			}

			if(answerNumber > randomNumber)
			{
				printf ("El numero ingresado es mayor al numero de oro");
				attempts++;
				continue;
			}

			if(answerNumber == randomNumber)
			{
				printf ("GANASTE!");
				break;
			}
		}

	} while (stillPlay == 's');

	return EXIT_SUCCESS;
}
