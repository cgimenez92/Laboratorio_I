/*
 * is_valid.h
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#ifndef IS_VALID_H_
#define IS_VALID_H_

/*
 * \brief Check if the pointer to char as a parameter is an integer.
 * \param char* string
 * \return (1) if the string passed by parameter is valid; (0) if it is not valid
 */
int isValidInt(char* string);

/*
 * \brief Check if the char as a parameter is an integer of one digit
 * \param char string
 * \return (1) if the char passed by parameter is valid; (0) if it is not valid
 */
int isValidOneInt(char string);

/*
 * \brief Check if the pointer to char as a parameter is an float.
 * \param char* string
 * \param int limit
 * \return (1) if the string passed by parameter is valid; (0) if it is not valid
 */
int isValidFloat(char* string, int limit);

/*
 * \brief Check if the pointer to char as a parameter is a valid name.
 * \param char* string
 * \param int limit
 * \return (1) if the string passed by parameter is valid; (0) if it is not valid
 */
int isValidName(char* string, int limit);

/*
 * \brief Check if the pointer to char as a parameter is a valid CUIT
 * \param char* string
 * \param int limit
 * \return (1) if the string passed by parameter is valid; (-2) if in position 2 or 11 form array there isn't a '-'; (-3) if in positions there isn't a number;
 */
int isValidCuit(char* string, int limit);

#endif /* IS_VALID_H_ */
