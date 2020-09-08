/*
 * get.h
 *
 *  Created on: 8 sep. 2020
 *      Author: cgimenez
 */

#ifndef GET_H_
#define GET_H_

int getFloat (char* pMessage, char* pErrorMessage2, float* pNumber, int attempts);
int getInt (char* pMessage, char* pErrorMessage, int* pNumber, int attempts);
int getOperation (char* pMessage, char* pErrorMessage, char* pOperation, int attempts);
int getIntWithLimits (char* pMessage, char* pErrorMessage, int* pNumber, int min, int max, int attempts);
// int getNumberWithLimits (char* pMessage, char* pErrorMessage, float* pNumber, int attempts); // A desarrollar;

#endif /* GET_H_ */
