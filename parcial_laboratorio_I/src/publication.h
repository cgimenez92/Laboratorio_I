///*
// * publicaction.h
// *
// *  Created on: 11 oct. 2020
// *      Author: cgimenez
// */

#ifndef PUBLICATION_H_
#define PUBLICATION_H_


#define TRUE 1
#define FALSE 0
#define STRING_SIZE 63
#define MIN_LIMIT 1
#define MAX_LIMIT 6
#define MIN_LIMIT_SALARY 1
#define MAX_LIMIT_SALARY 100000000
#define MIN_LIMIT_SECTOR 1
#define MAX_LIMIT_SECTOR 100
#define MAX_LIMIT_TEXT 64
#define LENGHT_ARRAY_STRUCT 3
#define ASC 1
#define DSC 0
#define ACTIVE 0
#define PAUSED 1
#include "customer.h"


	typedef struct
	{
		int id;
		int idCustomer;
		int isEmpty;
		int status;
		int itemNumber;
		char text[STRING_SIZE];
	}Publication;

	/** \brief add in a existing list of Customers the values received as parameters
	 * in the first empty position
	 * \param list Publication*
	 * \param len int
	 * \param name[] char
	 * \param lastName[] char
	 * \param salary float
	 * \param sector int
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
	free space] - (0) if Ok
	 */
	int publication_force_init(Publication* list, int len, int idCustomer, int status, int itemNumber, char* text);

	/** \brief To indicate that all position in the array are empty,
	 * this function put the flag (isEmpty) in TRUE in all
	 * position of the array
	 * \param list Publication* Pointer to array of Customers
	 * \param len int Array length
	 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	 */
    int publication_init(Publication* list, int len);

    /** \brief create a new Customer in list
     * in the first empty position
     * \param list Publication*
     * \param len int
     * \return int Return (-1) if Error [Invalid length or NULL pointer or without
    free space] - (0) if Ok
     */
    int publication_create(Publication* listPub, int lenPub, Customer* listCust, int lenCust);

	/** \brief print the content of Customers array
	 *
	 * \param list Publication*
	 * \param length int
	 * \return int
	 *
	 */
	int publication_print(Publication* list,int index);

	int publication_printArrayByIdCustomer(Publication* list , int len, int index);
//
//	int publication_printArray(Publication* list , int len);
//
//	/** \brief Remove a Customer by Id (put isEmpty Flag in 1)
//	 *
//	 * \param list Publication*
//	 * \param len int
//	 * \param id int
//	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
//	find a Customer] - (0) if Ok
//	 *
//	 */
	int publication_deleteByIdCustomer(Publication* listPub, int lenPub, Customer* listCust, int lenCust);
//	int publication_update(Publication* list, int len);
//	int publication_printIndex(Publication* list, int len, int index);
	int publication_freePosition(Publication* list, int len);
//	int publication_freePositionIndex(Publication* list, int len, int* pIndex);
//
//	/** \brief find an Customer by Id en returns the index position in array.
//	 *
//	 * \param list Publication*
//	 * \param len int
//	 * \param id int
//	 * \return Return Customer index position or (-1) if [Invalid length or NULL
//	pointer received or Customer not found]
//	 *
//	 */
	int publication_searchIdCustomerById(Publication* list, int len, int id);
//
//	/** \brief Sort the elements in the array of Customers, the argument order
//	indicate UP or DOWN order
//	 *
//	 * \param list Publication*
//	 * \param len int
//	 * \param order int [1] indicate UP - [0] indicate DOWN
//	 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
//	 *
//	 */
	int publication_sortArray(Publication* list, int len, int order);
//
//	int publication_avgSalary(Publication* list, int len, float* avgValue);
//	int publication_sumSalary(Publication* list, int len, float* totalValue);
//
	int publication_changeState(Publication* listPub, int lenPub, Customer* listCust, int lenCust, int state);
	int publication_countByCustomer(Publication* listPub, int lenPub, Customer* listCust, int lenCust);
//
#endif /* PUBLICATION_H_ */
