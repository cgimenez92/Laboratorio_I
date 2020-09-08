/*
 ============================================================================
 Name        : ejercicio_004.c
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
	int qNegatives = 0;
	int qPositives = 0;

	for(i=0; i<10; i++)
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

		 if(number < 0)
		 {
			 qNegatives++;
		 }
		 else
			 {
			 	 qPositives++;
			 }
	}

	printf("Cantidad de numeros positivos %d.\n", qPositives);
	printf("Cantidad de numeros negativos %d.\n", qNegatives);

	return EXIT_SUCCESS;
}
