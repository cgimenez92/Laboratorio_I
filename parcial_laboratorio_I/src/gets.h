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
int getYesOrNo(char* message, char* firstErrorMessage, char* secondErrorMessage, char* pChar, int attempts, int stringSize);

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

/*
 * \brief Obtiene una operacion matematica, valida
 * \param char* message
 * \param char* errorMessage
 * \param char* pResult
 * \param char* operation
 * \param int attempts
 * \return (1) si obtuvo alguno de los caracteres (+; -;/ ;*) y es valido (0) Error
 */
int getCuit(char* message, char* firstErrorMessage, char* secondErrorMessage, char* pResult, int attempts, int stringSize);

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error de tipo
 * \param errorMessageLenght Es el mensaje a ser mostrado en caso de error de longitud
 * \param input Array donde se cargará el texto ingresado
 * \param maxLenght int Longitud maxima del texto ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el String -1 si no
 *
 */
int getString(char* message, char* errorMessageLenght, char* pResult, int attempts, int stringSize);

#endif /* GETS_H_ */
