/*
 ============================================================================
 Name        : ejercicio_video_clase_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Programa que pida un numero al usuario , despues que pida una operacion (+ - / *)
 y despues que pida otro numero. segun l aoperacion ingresada se llamar a una funcón
 que ejecute la operacion sumar() restar() multiplicar() dividir()
 Finalmente mostrar al usuario el resultado (no puede estar dentro de la funciones)

 */

#include <stdio.h>
#include <stdlib.h>
int getFloat (char* message, char* errorMessage, float* number, int attempts);
int getOperation(char* message, char* errorMessage, char* operation, int attempts);
int sumOperation(float* firstOperator, float* secondOperator, float* result);
int restOperation(float* firstOperator, float* secondOperator, float* result);
int divideOperation(float* firstOperator, float* secondOperator, float* result);
int multiplyOperation(float* firstOperator, float* secondOperator, float* result);

int main(void)
{
	setbuf(stdout,NULL);
	float firstNumber, secondNumber, result;
	char operation;

	getFloat ("Ingrese el primer numero: \n", "Ingrese un caracter numerico: \n", &firstNumber, 2);
	getOperation("Ingrese operacion: \n", "Unicas operaciones validas '+ - / *' \n", &operation, 2);
	getFloat ("Ingrese el segundo numero: \n", "Ingrese un caracter numerico: \n", &secondNumber, 2);

	if(operation == '+')
	{
		sumOperation(&firstNumber, &secondNumber, &result);
		printf("El resultado de la suma es: %.2f \n", result);
	}

	if(operation == '-')
	{
		restOperation(&firstNumber, &secondNumber, &result);
		printf("El resultado de la resta es: %.2f \n", result);
	}


	if(operation == '/')
	{
		if(divideOperation(&firstNumber, &secondNumber, &result)==0)
		{
			printf("El resultado de la division es: %.2f \n", result);
		}
		else
		{
			printf("No se puede dividir por 0 \n");
		}
	}


	if(operation == '*')
	{
		multiplyOperation(&firstNumber, &secondNumber, &result);
		printf("El resultado de la multiplicacion es: %.2f \n", result);
	}

	return EXIT_SUCCESS;
}

int sumOperation(float* firstOperator, float* secondOperator, float* result)
{
	*result = *firstOperator + *secondOperator;

return 0;
}

int restOperation(float* firstOperator, float* secondOperator, float* result)
{
	*result = *firstOperator - *secondOperator;

return 0;
}


int divideOperation(float* firstOperator, float* secondOperator, float* result)
{
	int ret = -1;

	if (*secondOperator != 0)
	{
		*result = *firstOperator / *secondOperator;
		ret =0;
	}

	return ret;
}



int multiplyOperation(float* firstOperator, float* secondOperator, float* result)
{
	*result = *firstOperator * *secondOperator;

return 0;
}


int getOperation(char* message, char* errorMessage, char* operation, int attempts)
{
	int ret = 0;

	printf(message);
	fflush(stdin);
	scanf("%c", operation);

	while(attempts >= 0 && (*operation != '+' && *operation != '-' && *operation != '/' && *operation != '*'))
		{
			printf(errorMessage);
			fflush(stdin);
			scanf("%c", operation);
			attempts--;

			if(attempts==0)
			{
				ret = -1;
			}
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

	return ret;
}
