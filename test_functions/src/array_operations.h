/*
 * array_operations.h
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#ifndef ARRAY_OPERATIONS_H_
#define ARRAY_OPERATIONS_H_

int printArrayInt(int* pArray, int arraySize);
int sortArrayDsc(int* pArray, int arraySize);
int sortArrayAsc(int* pArray, int arraySize);
int swapPostionInArray (int* pArray, int buffer, int positionToSwap);
int maxIntArray(int* pArray, int arraySize, int* maxValue);
int minIntArray(int* pArray, int arraySize, int* minValue);
int avgArray(int* pArray, int arraySize, float* avgValue);

#endif /* ARRAY_OPERATIONS_H_ */
