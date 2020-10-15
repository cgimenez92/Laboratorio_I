/*
 * gets.h
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#ifndef GETS_H_
#define GETS_H_

/*
 * \brief Obtains a char 'S' or 'N'
 * \param char* firstErrorMessage
 * \param char* secondErrorMessage
 * \param char* pChar
 * \param int attempts
 * \param int stringSize
 * \return Return (-1) if Error [Invalid length or NULL pointer or without free space] (0); if char is a 'S' (-2) if char is a 'N'; (-3) if char isn't a 'S' or 'N';
 */
int getYesOrNo(char* message, char* firstErrorMessage, char* secondErrorMessage, char* pChar, int attempts, int stringSize);

/*
 * \brief Obtains a valid name
 * \param char* message
 * \param char* errorMessage
 * \param char* pResult
 * \param int attempts
 * \param int stringSize
 * \return Return (-1) if Error [Invalid length or NULL pointer or without free space]; (0) if char is a 'S' (-2) if char is a 'N'; (-3) if char isn't a 'S' or 'N';
 */
int getName(char* message, char* errorMessage, char* pResult, int attempts, int stringSize);

/*
 * \brief Obtains a valid integer with limits
 * \param char* message
 * \param char* errorMessage
 * \param char* pResult
 * \param int attempts
 * \param int min
 * \param int max
 * \return (1) si obtuvo un entero y es valido (0) Error
 */
int getInt(char* message, char* errorMessage, int* pResult, int attempts, int min, int max);

/*
 * \brief Obtains a valid float with limits
 * \param char* message
 * \param char* errorMessage
 * \param char* pResult
 * \param int attempts
 * \param float min
 * \param float max
 * \return (0) if obtain a name and is valid; (-1) Error [Invalid length or NULL pointer or without free space]
 */
int getFloat (char* message, char* errorMessage, float* pResult, int attempts, float min, float max);

/*
 * \brief Obtains symbol of a mathemathic operation
 * \param char* message
 * \param char* errorMessage
 * \param char* pResult
 * \param char* operation
 * \param int attempts
 * \return (0) if obtain a symbol  (+; -;/ ;*)  and is valid; (-1) Error [Invalid length or NULL pointer or without free space]
 */
int getOperation(char* message, char* errorMessage, char* operation, int attempts);

/*
 * \brief Obtains a valid CUIT wiht parameters
 * \param char* message
 * \param char* firstErrorMessage
 * \param char* secondErrorMessage
 * \param char* pResult
 * \param char* operation
 * \param int attempts
 * \paramint stringSize
 * \return (0) if obtain a CUIT and is valid; (-1) Error [Invalid length or NULL pointer or without free space]
 */
int getCuit(char* message, char* firstErrorMessage, char* secondErrorMessage, char* pResult, int attempts, int stringSize);

/**
 * \brief Obtains a array of char (string) with limits
 * \param char* message
 * \param char* errorMessageLenght
 * \param char* pResult
 * \param int attempts
 * \param int stringSize
 * \return (0) if obtain a string and is valid; (-1) Error [Invalid length or NULL pointer or without free space]
 *
 */
int getString(char* message, char* errorMessageLenght, char* pResult, int attempts, int stringSize);

#endif /* GETS_H_ */
