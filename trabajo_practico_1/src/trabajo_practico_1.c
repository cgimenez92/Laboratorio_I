/*
 ============================================================================
 Name        : trabajo_practico_1.c
 Author      : cgimenez
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculator_operations.h"
#include "utn.h"

int main(void)
{
		setbuf(stdout,NULL);
	  	char questionContinue = 'N';
	  	int flagOk;
	    int option;
	    float firstOperator;
	    float secondOperator;
	    float result;
	    unsigned long int firstResultFactorial;
	    unsigned long int secondResultFactorial;

	    do
	    {
			flagOk = getIntWithLimits("\n1- Ingresar 1er operando (A)\n2- Ingresar 2do operando (B)\n3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n"
					"6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operaciones\n9- Salir\n\nSeleccione una opcion: ",
					"Ingresar una opcion entre [1-9]", "Ingresar un caracter numerico", &option, 3, 1, 9);

			if(!flagOk)
			{
				switch(option)
				{
				case 1:
					getFloat ("Ingrese primer numero: ", "Ingrese un caracter numerico: ", &firstOperator, 3);
					break;

				case 2:
					getFloat ("Ingrese segundo numero: ", "Ingrese un caracter numerico: ", &secondOperator, 3);
					break;

				case 3:

					if(!fSumOperation(firstOperator, secondOperator, &result))
					{
						printf("\nEl resultado de la suma es %.2f \n", result);
					}
					else
						{
						printf("\nError\n");
						}
					break;

				case 4:
					if(!fRestOperation(firstOperator, secondOperator, &result))
					{
						printf("\nEl resultado de la resta es %.2f \n", result);
					}
					else
						{
						printf("\nError\n");
						}
					break;

				case 5:
					if(secondOperator == 0)
					{
						printf("\nNo es posible realizar Division por 0\nFavor de ingresar el segundo operando distinto de 0\n\n");
					}
					else
						{
							fDivideOperation(firstOperator, secondOperator, &result);
							printf("\nEl resultado de la division es %.2f \n", result);
						}
					break;

				case 6:
					if(!fMultiplyOperation(firstOperator, secondOperator, &result))
					{
						printf("\nEl resultado de la multiplicacion es %.2f \n", result);
					}
					else
						{
						printf("\nError\n");
						}
					break;

				case 7:
					if(!fFactorial(firstOperator, secondOperator, &firstResultFactorial, &secondResultFactorial))
					{
						printf("\nEl resultado factorial del primer operador es %ld \n", firstResultFactorial);
						printf("\nEl resultado factorial del segundo operador es %ld \n", secondResultFactorial);
					}
					else
						{
							if(fFactorial(firstOperator, secondOperator, &firstResultFactorial, &secondResultFactorial)== -2)
								printf("\nPrimer operador menor a 0, no es posible realizar el calculo\n");
							if(fFactorial(firstOperator, secondOperator, &firstResultFactorial, &secondResultFactorial)== -3)
								printf("\nSegundo operador menor a 0, no es posible realizar el calculo \n");
						}
					break;

				case 8:
					//Suma
					if(!fSumOperation(firstOperator, secondOperator, &result))
					{
						printf("\nEl resultado de la suma es %.2f \n", result);
					}
					else
						{
						printf("\nError\n");
						}

					//Resta
					if(!fRestOperation(firstOperator, secondOperator, &result))
					{
						printf("\nEl resultado de la resta es %.2f \n", result);
					}
					else
						{
						printf("\nError\n");
						}

					//Division
					if(secondOperator == 0)
					{
						printf("\nNo es posible realizar Division por 0\nFavor de ingresar el segundo operando distinto de 0\n\n");
					}
					else
						{
							fDivideOperation(firstOperator, secondOperator, &result);
							printf("\nEl resultado de la division es %.2f \n", result);
						}

					//Multiplicacion
					if(!fMultiplyOperation(firstOperator, secondOperator, &result))
					{
						printf("\nEl resultado de la multiplicacion es %.2f \n", result);
					}
					else
						{
						printf("\nError\n");
						}

					//Factorial
					if(!fFactorial(firstOperator, secondOperator, &firstResultFactorial, &secondResultFactorial))
					{
						printf("\nEl resultado factorial del primer operador es %lu \n", firstResultFactorial);
						printf("\nEl resultado factorial del segundo operador es %lu \n", secondResultFactorial);
					}
					else
						{
							if(fFactorial(firstOperator, secondOperator, &firstResultFactorial, &secondResultFactorial)== -2)
								printf("\nPrimer operador menor a 0, no es posible realizar el calculo\n");
							if(fFactorial(firstOperator, secondOperator, &firstResultFactorial, &secondResultFactorial)== -3)
								printf("\nSegundo operador menor a 0, no es posible realizar el calculo \n");
						}
					break;

				case 9:
					printf("\n *** Adios! *** \n");
					questionContinue = 'N';
					break;
				}
			}
			else
				{
					getChar("\n *** Se acabaron los intentos, volver a ejecutar la calculadora *** \n¿Continuar? - S/N \n", &questionContinue);

					if(toupper(questionContinue) == 'S')
					{
						continue;
					}
					else
						{
							break;
						}
				}

	    } while(toupper(questionContinue) == 'S' || option != 9);

	    return EXIT_SUCCESS;
}
