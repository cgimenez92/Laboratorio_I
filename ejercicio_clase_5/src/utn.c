/*
 * utn.c
 *
 *  Created on: 8 sep. 2020
 *      Author: cgimenez
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Solicita un entero al usuario
 * \param char* pMessage
 * \param char* pErrorMessage
 * \param int* pNumber
 * \param int min
 * \param int max
 * \param int attempts
 * \return
 */

int getIntWithLimits (char* pMessage, char* pErrorMessage, int* pNumber, int min, int max, int attempts)
{
	int ret = -1;
	int bufferInt;
	int answerScanf;

	if (pMessage != NULL && pErrorMessage != NULL && pNumber != NULL && min <= max && attempts >=0)
	{
		printf("%s",pMessage);
		fflush(stdin);
		answerScanf = scanf("%d",&bufferInt);

		while (attempts >= 0)
		{
			if (answerScanf != 1)
			{
				if(bufferInt >= min && bufferInt <= max)
				{
					break;
				}

				if(attempts==0)
				{
					ret = -2;
				}

				attempts--;
				printf("%s",pErrorMessage);
			}
			else
				{
					*pNumber = bufferInt;
					ret = 0;
					break;
				}
		}
	}

	return ret;
}
