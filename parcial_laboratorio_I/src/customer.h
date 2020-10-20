/*
 * customer.h
 *
 *  Created on: 11 oct. 2020
 *      Author: cgimenez
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#define TRUE 1
#define FALSE 0
#define ASC 1
#define DSC 0
#define ACTIVE 0
#define PAUSED 1
#define ALL 2
#define CUIT_SIZE 15
#define LIMIT_TEXT 64
#define STRING_SIZE 64
#define ARRAY_SIZE_ADS 1000
#define MIN_LIMIT_CLIENT 1
#define MAX_LIMIT_CLIENT 100
#define ARRAY_SIZE_CUSTOMER 100
#define MIN_LIMIT_PUBLICATION 1
#define MAX_LIMIT_PUBLICATION 1000
#define MIN_LIMIT_ITEM_NUMBER 1
#define MAX_LIMIT_ITEM_NUMBER 50

	typedef struct
	{
		int id;
		int isEmpty;
		char name[STRING_SIZE];
		char lastName[STRING_SIZE];
		char cuit[STRING_SIZE];
	} Customer;

	/** \brief adds in a existing list, a list of Customers with  the values received as parameters
	 * \param Customer* list
	 * \param int len
	 * \param char* name
	 * \param char* lastName
	 * \param char* cuit
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
	 */
	int customer_force_init	 (Customer* list, int len, char* name, char* lastName, char* cuit);

	/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
	 * \param Customer* list Pointer to array of Customers
	 * \param int len Array length
	 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	 */
	int customer_init	   	 (Customer* list, int len);

    /** \brief create a new Customer in list
     * in the first empty position
     * \param Customer* list
     * \param int len
     * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (index) if Ok
     */
	int customer_create	   	 (Customer* list, int len);


    /** \brief chooses parameter you want to change in Customer list
     * in the first empty position
     * \param Customer* list
     * \param int len
     * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
     */
	int customer_update		 (Customer* list, int len);

	/** \brief Remove a Customer by Id (put isEmpty Flag in 1)
	 * \param list Customer*
	 * \param len int
	 * \param id int
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
//	int customer_delete		 (Customer* listCust, int lenCust, Publication* listPub, int lenPub);


	/** \brief prints the content of Customers received on index parameter
	 * \param list Customer*
	 * \param length int
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int customer_print		 (Customer* list, int index);

	/** \brief print the content of Customers array
	 * \param list Customer*
	 * \param length int
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int customer_printArray	 (Customer* list, int len);

	/** \brief find a empty position in customer array and returns the index position in array.
	 * \param list Customer*
	 * \param len int
	 * \param id int
	 * \return Return Customer index position or (-1) if [Invalid length or NULL pointer received or Customer not found] - (i --> Index of position free) if Ok
	 */
	int customer_freePosition(Customer* list, int len);


	/** \brief find a empty position in customer array and returns the index position in array.
	 * \param list Customer*
	 * \param len int
	 * \param int* pIndex
	 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int customer_freePositionIndex(Customer* list, int len, int* pIndex);

	/** \brief find an Customer by Id and returns the index position in array.
	 * \param list Customer*
	 * \param len int
	 * \param id int
	 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int customer_searchId	 (Customer* list, int len, int id);

#endif /* CUSTOMER_H_ */
