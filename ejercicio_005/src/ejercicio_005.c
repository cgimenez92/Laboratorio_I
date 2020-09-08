/*
 ============================================================================
 Name        : ejercicio_005.c
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
	setbuf(stdout,NULL);

	int number;
	int answerScanf, i;
	int retainMax = 0;
	int retainMin = 0;
	int retainAvg = 0;
	int max = 0;
	int min = 0;
	float avg = 0;

	for(i=0; i<5; i++)
	{
		printf("Ingrese un numero: \n");
		fflush(stdin);
		answerScanf = scanf("%d",&number);

		while(answerScanf != 1)
			{
				printf("Ingrese un caracter numerico: \n");
				fflush(stdin);
				answerScanf = scanf("%d",&number);
			}

		retainMax = number;
		retainMin = number;
		retainAvg = +number;

		 if(retainMax > max)
			 {
				 max = retainMax;
			 }

		 if(retainMin < min)
			 {
				 min = retainMin;
			 }
	}

	avg = retainAvg/i++;

	printf("Promedio: %f.\n", avg);
	printf("Maximo: %d.\n", max);
	printf("Minimo: %d.\n", min);

	return EXIT_SUCCESS;
}
