/*
 ============================================================================
 Name        : ejercicio_002.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
	{
		setbuf(stdout, NULL);
		int firstNumber, secondNumber, result, answerScanf;

		printf("Ingrese su primer numero: \n");
		answerScanf = scanf("%d",&firstNumber);
		while (firstNumber == 0 || answerScanf != 1)
		{
			if(answerScanf != 1)
			{
				printf("Ingrese un caracter numerico: \n");
				fflush(stdin);
			}

			if (firstNumber == 0)
			{
				printf("El numero debe ser distinto de 0 - Ingrese su primer numero: \n");
				fflush(stdin);
			}

			answerScanf = scanf("%d",&firstNumber);
		}

		printf("Ingrese su segundo numero: \n");
		answerScanf = scanf("%d",&secondNumber);
		while (secondNumber == 0 || answerScanf != 1)
		{
			if(answerScanf != 1)
			{
				printf("Ingrese un caracter numerico: \n");
				fflush(stdin);
			}

			if (secondNumber == 0)
			{
				printf("El numero debe ser distinto de 0 - Ingrese su segundo numero: \n");
				fflush(stdin);

			}

			answerScanf = scanf("%d",&secondNumber);
		}

		result = firstNumber - secondNumber;

		if(result > 0)
		{
			printf("Resultado positivo: %d\n", result);
		}
		else
			{
			if (result==0)
			{
				printf("Resultado nulo %d\n", result);
			}
			else
				{
					printf("Resultado negativo: %d\n", result);
				}
			}

		return EXIT_SUCCESS;
	}
