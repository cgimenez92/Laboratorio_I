/*
 * array_functions.h
 *
 *  Created on: 28 sep. 2020
 *      Author: cgimenez
 */

#ifndef ARRAY_FUNCTIONS_H_
#define ARRAY_FUNCTIONS_H_

int printArrayInt(int* pArray, int sizeArray);
int sortArrayDsc(int* pArray, int arraySize);
int sortArrayAsc(int* pArray, int arraySize);
int swapPostionInArray (int* pArray, int buffer, int positionToSwap);
int maxIntArray(int* pArray, int arraySize, int* maxValue);
int minIntArray(int* pArray, int arraySize, int* minValue);
int avgArray(int* pArray, int arraySize, float* avgValue);

#endif /* ARRAY_FUNCTIONS_H_ */
