/*
 ============================================================================
 Name        : ejercicio_006.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int getFloat (char* message, char* errorMessage, float* number, int attempts);
int getRadioReturnArea(float* radio, float* area);

int main(void)
{
	setbuf(stdout,NULL);
	float firstNumber, area;

	if(getFloat ("Ingrese el primer numero: \n", "Ingrese un caracter numerico: \n", &firstNumber, 2)==0)
	{
		if (getRadioReturnArea(&firstNumber, &area)==0)
		{
			printf("El area del circulo es %.2f \n", area);
		}
		else
		{
			printf("El radio de un circulo no puede ser negativo \n");
		}

	}

	return EXIT_SUCCESS;
}


int getRadioReturnArea(float* radio, float* area)
{
	int ret = -1;

	if (*radio > 0)
		{
			*area = 3.14 ** radio ** radio;
			ret = 0;
		}

	return ret;
}

int getFloat (char* message, char* errorMessage, float* number, int attempts)
{
	int ret = 0;
	int answerScanf;

	printf(message);
	fflush(stdin);
	answerScanf = scanf("%f",number);

	while(attempts>=0 && answerScanf != 1)
		{
			printf(errorMessage);
			fflush(stdin);
			answerScanf = scanf("%f",number);
			attempts--;

			if(attempts==0)
			{
				ret = -1;
			}
		}
	printf("%.2f \n",*number);
	return ret;
}
