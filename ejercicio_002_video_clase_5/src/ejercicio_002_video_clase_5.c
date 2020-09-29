/*
 ============================================================================
 Name        : ejercicio_002_video_clase_5.c
 Author      : cgimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define QTY_EMPLOYEES 9

int calcAvgValues(float* arrayAvg, float* pResultAvg, int arraySize);

int main(void)
{
	float ageAvg;
	float age_employees[QTY_EMPLOYEES] = {54,26,93,17,77,31,44,55,27};
	calcAvgValues(age_employees, &ageAvg, QTY_EMPLOYEES);
	printf("%.2f\n", ageAvg);




	return EXIT_SUCCESS;
}

/**
 * \brief Se pasa un array cargado de floats y devuelve en un puntero su promedio
 * \param float* arrayAvg puntero de arrays.
 * \param float* pResultAvg puntero al espacio de memoria donde se dejara el promedio calculado del array.
 * \param int arraySize tamaño del array
 * \return (0) Puntero arrayAvg y pResultAvg no es nulo (Ok)/ (-1) Puntero arrayAvg y pResultAvg es nulo (Error)
 */


int calcAvgValues(float* arrayAvg, float* pResultAvg, int arraySize)
{
	int ret;
	float bufferArrayresult=0;
	int i;

	if (arrayAvg!=NULL && pResultAvg!=NULL && arraySize>0)
	{
		for(i=0;i<arraySize;i++)
		{
			bufferArrayresult += arrayAvg[i];
		}

		*pResultAvg=bufferArrayresult/arraySize;
		ret=0;
	}

	return ret;
}
