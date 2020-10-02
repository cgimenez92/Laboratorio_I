/*
 * gets.h
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#ifndef GETS_H_
#define GETS_H_
#define BUFFER_SIZE 4096

int getName(char* message, char* errorMessage, char* pResult, int attempts, int stringSize);
int getInt(char* message, char* errorMessage, int* pResult, int attempts, int min, int max);
int getFloat (char* message, char* errorMessage, float* pResult, int attempts, float min, float max);
int getOperation(char* message, char* errorMessage, char* operation, int attempts);

#endif /* GETS_H_ */
