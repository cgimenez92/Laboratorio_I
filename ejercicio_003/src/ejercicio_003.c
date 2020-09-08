/*
 ============================================================================
 Name        : ejercicio_003.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	setbuf(stdout, NULL);
	int firstNumber, secondNumber, result;

	printf("\nIngrese 1 numero: ");
	scanf("%d",&firstNumber);
	if(firstNumber )



	printf("\nIngrese 2 numero: ");
	scanf("%d",&secondNumber);

	result=firstNumber-secondNumber;

	printf("______________________________________\n");
	printf("\nEl resultado es: %d \n",result);

	if(result>0)
		{
			printf("\nResultado positivo \n");
		}

	if(result==0)
		{
			printf("\nResultado negativo \n");
		}
	printf("______________________________________\n\n\n\n");


	return 0;
}
