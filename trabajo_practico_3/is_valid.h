/*
 * is_valid.h
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#ifndef IS_VALID_H_
#define IS_VALID_H_

/*
 * \brief Verifica si el puntero a char pasado como parametro es un entero.
 * \param char*cadena
 * \return (1) si es valido el string pasado por parametro; (0) si no es valido
 */
int isValidInt(char*string);

/*
 * \brief Verifica si el puntero a char pasado como parametro es un flotante.
 * \param char* string
 * \param int limit
 * \return (1) si es valido el string pasado por parametro; (0) si no es valido
 */
int isValidFloat(char* string, int limit);

/*
 * \brief Verifica si el puntero a char pasado como parametro es un nombre valido.
 * \param char* string
 * \param int limit
 * \return (1) si es valido el string pasado por parametro; (0) si no es valido
 */
int isValidName(char*string, int limit);

#endif /* IS_VALID_H_ */
