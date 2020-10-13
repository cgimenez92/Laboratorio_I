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
#define STRING_SIZE 63
#define CUIT_SIZE 15
#define MIN_LIMIT 1
#define MAX_LIMIT 6
#define MIN_LIMIT_SALARY 1
#define MAX_LIMIT_SALARY 100000000
#define MIN_LIMIT_SECTOR 1
#define MAX_LIMIT_SECTOR 100
#define LENGHT_ARRAY_STRUCT 3
#define ASC 1
#define DSC 0

	typedef struct
	{
		int id;
		int isEmpty;
		char name[STRING_SIZE];
		char lastName[STRING_SIZE];
		char cuit[STRING_SIZE];
	} Customer;

	/** \brief add in a existing list of Customers the values received as parameters
	 * in the first empty position
	 * \param list Customer*
	 * \param len int
	 * \param name[] char
	 * \param lastName[] char
	 * \param salary float
	 * \param sector int
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
	free space] - (0) if Ok
	 */
	int customer_force_init(Customer* list, int len, char* name, char* lastName, char* cuit);

	/** \brief To indicate that all position in the array are empty,
	 * this function put the flag (isEmpty) in TRUE in all
	 * position of the array
	 * \param list Customer* Pointer to array of Customers
	 * \param len int Array length
	 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	 */
    int customer_init(Customer* list, int len);

    /** \brief create a new Customer in list
     * in the first empty position
     * \param list Customer*
     * \param len int
     * \return int Return (-1) if Error [Invalid length or NULL pointer or without
    free space] - (0) if Ok
     */
	int customer_create(Customer* list, int len);

	/** \brief print the content of Customers array
	 *
	 * \param list Customer*
	 * \param length int
	 * \return int
	 *
	 */
	int customer_print(Customer* list,int index);


	int customer_printArray(Customer* list , int len);

	/** \brief Remove a Customer by Id (put isEmpty Flag in 1)
	 *
	 * \param list Customer*
	 * \param len int
	 * \param id int
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
	find a Customer] - (0) if Ok
	 *
	 */
//	int customer_delete(Customer* listCust, int lenCust, Publication* listPub, int lenPub);
	int customer_update(Customer* list, int len);
	int customer_printIndex(Customer* list, int len, int index);
	int customer_freePosition(Customer* list, int len);
	int customer_freePositionIndex(Customer* list, int len, int* pIndex);

	/** \brief find an Customer by Id en returns the index position in array.
	 *
	 * \param list Customer*
	 * \param len int
	 * \param id int
	 * \return Return Customer index position or (-1) if [Invalid length or NULL
	pointer received or Customer not found]
	 *
	 */
	int customer_searchId(Customer* list, int len, int id);

	/** \brief Sort the elements in the array of Customers, the argument order
	indicate UP or DOWN order
	 *
	 * \param list Customer*
	 * \param len int
	 * \param order int [1] indicate UP - [0] indicate DOWN
	 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	 *
	 */
	int customer_sortArray(Customer* list, int len, int order);

	int customer_avgSalary(Customer* list, int len, float* avgValue);
	int customer_sumSalary(Customer* list, int len, float* totalValue);


#endif /* CUSTOMER_H_ */
