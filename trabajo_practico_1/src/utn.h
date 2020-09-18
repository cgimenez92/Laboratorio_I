/*
 * utn.h
 *
 *  Created on: 8 sep. 2020
 *      Author: cgimenez
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * \brief Solicita un entero al usuario
 * \param char* pMessage Mensaje a ser mostrado al usuario
 * \param char* pErrorMessage Mensaje de error a ser mostrado al usuario
 * \param int* pNumber puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param int min Valor minimo de obtención
 * \param int max Valor maximo de obtención
 * \param int attempts Cantidad de intentos
 * \return (-1) Error / (0) Ok
 */
int getIntWithLimits(char* message, char* firstErrorMessage, char* secondErrorMessage, int* pNumber, int attempts, int min, int max);

/**
 * \brief Solicita un numero flotante al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 */
int getFloat(char* message, char* errorMessage, float* pNumber, int attempts);

/**
 * \brief Solicita un entero al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario para el ingreso del caracter
 * \param int* pChar, puntero al espacio de memoria donde se dejara el valor del caracter obtenido
 * \return (-1) Error / (0) Ok
 */
int getChar(char* message, char* pChar);

#endif /* UTN_H_ */
