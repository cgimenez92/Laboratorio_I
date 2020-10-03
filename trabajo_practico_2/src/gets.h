/*
 * gets.h
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#ifndef GETS_H_
#define GETS_H_
#define BUFFER_SIZE 4096

/*
 * \brief Obtiene un nombre
 * \param char* message
 * \param char* errorMessage
 * \param char* pResult
 * \param int attempts
 * \param int stringSize
 * \return (1) si obtuvo el nombre y es valido (0) Error
 */
int getName(char* message, char* errorMessage, char* pResult, int attempts, int stringSize);

/*
 * \brief Obtiene un entero, valido y con limites
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
 * \brief Obtiene un flotante, valido y con limites
 * \param char* message
 * \param char* errorMessage
 * \param char* pResult
 * \param int attempts
 * \param float min
 * \param float max
 * \return (1) si obtuvo el nombre y es valido (0) Error
 */
int getFloat (char* message, char* errorMessage, float* pResult, int attempts, float min, float max);

/*
 * \brief Obtiene una operacion matematica, valida
 * \param char* message
 * \param char* errorMessage
 * \param char* pResult
 * \param char* operation
 * \param int attempts
 * \return (1) si obtuvo alguno de los caracteres (+; -;/ ;*) y es valido (0) Error
 */
int getOperation(char* message, char* errorMessage, char* operation, int attempts);

#endif /* GETS_H_ */
