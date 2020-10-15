///*
// * publicaction.h
// *
// *  Created on: 11 oct. 2020
// *      Author: cgimenez
// */

#ifndef PUBLICATION_H_
#define PUBLICATION_H_

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

	/** \brief adds in a existing list, a list of Publications with  the values received as parameters
	 * \param Publication* list
	 * \param int len
	 * \param int idCustomer
	 * \param int status
	 * \param int itemNumber
	 * \param char* text
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
	 */
	int publication_force_init(Publication* list, int len, int idCustomer, int status, int itemNumber, char* text);

	/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
	 * \param Publication* list Pointer to array of Customers
	 * \param int len Array length
	 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	 */
	int publication_init(Publication* list, int len);

	/** \brief prints the content of Publication received on index parameter
	 * \param Publication* list
	 * \param int index
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int publication_print(Publication* list,int index);

	/** \brief print the content of Publication array
	 * \param Publication* list
	 * \param int len
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int publication_printArray(Publication* list , int len);

	/** \brief prints the content of Publication received on index parameter
	 * \param Publication* list
	 * \param int len
	 * \param int index
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int publication_printArrayByIdCustomer(Publication* list , int len, int index);

	/** \brief create a new Publication in list in the first empty position
	 * \param Publication* listPub
	 * \param int lenPub
	 * \param Customer* listCust
	 * \param int lenCus
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (index) if Ok
	 */
	int publication_create(Publication* listPub, int lenPub, Customer* listCust, int lenCust);


	/** \brief chooses parameter you want to change in Publication list (ACTIVE - PAUSED)
	* Publication* listPub
	* \param int lenPub
	* \param Customer* listCust
	* \param int lenCust
	* \param int state
	* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
	*/
	int publication_changeState(Publication* listPub, int lenPub, Customer* listCust, int lenCust, int state);

	/** \brief Remove a publication searching Id customer
	 * \param list Publication*
	 * \param int lenPub
	 * \param Customer* listCust
	 * \param int lenCust
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int publication_deleteByIdCustomer(Publication* listPub, int lenPub, Customer* listCust, int lenCust);


	/** \brief find a empty position in Publication array and returns the index position in array.
	 * \param list Publication*
	 * \param len int
	 * \param int* pIndex
	 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a Customer] - (0) if Ok
	 */
	int publication_freePositionIndex     (Publication* list, int len, int* pIndex);

	/** \brief find a empty position in Publication array
	 * \param Publication* list
	 * \param int len
	 * \return Return Customer index position or (-1) if [Invalid length or NULL pointer received or Customer not found] -  (i --> Index of position free) if Ok
	 */
	int publication_freePosition(Publication* list, int len);

	/** \brief find an Customer by Id en returns the index position in array.
	 * \param list Publication*
	 * \param len int
	 * \param id int
	 * \return Return if ok customer index position (list[i].idCustomer) or (-1) if [Invalid length or NULL pointer received or Customer not found]
	 */
	int publication_searchIdCustomerById(Publication* list, int len, int id);

	/** \brief Sort the elements in the array of Publication, the argument order indicate UP or DOWN order
	 * \param list Publication*
	 * \param len int
	 * \param order int [1] indicate UP - [0] indicate DOWN
	 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	 */
	int publication_sortArray(Publication* list, int len, int order);



	int publication_activePerCustomer(Publication* listPub, int lenPub, Customer* listCust, int lenCust);
#endif /* PUBLICATION_H_ */
