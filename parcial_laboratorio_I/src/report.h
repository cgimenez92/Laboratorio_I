///*
// * reports.h
// *
// *  Created on: 12 oct. 2020
// *      Author: cgimenez
// */

#ifndef REPORT_H_
#define REPORT_H_

/** \brief go over the arrays and increases the flags of distinct states of publications
 * \param Publication* listPub
 * \param int lenPub
 * \param int idCustomer
 * \param int* qPublications
 * \param int* qPublicationsActives
 * \param int* qPublicationsPaused
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int report_countPublications(Publication* listPub, int lenPub, int idCustomer, int* qPublications,  int* qPublicationsActives,  int* qPublicationsPaused);

/** \brief Crosses the arrays of the entities and it acquires depends of status, the customer and q of publications
 * \param Publication* listPub
 * \param int lenPub
 * \param Customer* listCust
 * \param int lenCust
 * \param int statusPublication
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int report_customerCountPublications(Publication* listPub, int lenPub, Customer* listCust, int lenCust, int statusPublication);

/** \brief list the arrays of publications and acquires the one that it is more paused status
 * \param Publication* list
 * \param int len
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int report_qPublicationsPaused(Publication* list, int len);

/** \brief Crosses the arrays of the entities and it acquires the one that have more of the same item number in distinct publications
 * \param Publication* list
 * \param int len
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int report_itemNumberWithMorePublications(Publication* list, int len);

/** \brief Sort the arrays of publications and print the distinct item number
 * \param Publication* listPub
 * \param int lenPub
 * \param Customer* listCust
 * \param int lenCust
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int report_sortArrayByItemNumber(Publication* list, int len);

/** \brief Sum publications where his status is active.
 * \param Publication* listPub
 * \param int lenPub
 * \param int* qPublications
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int report_qPublications(Publication* listPub, int lenPub, int* qPublications);

/** \brief Enter by console a number of item and print the number of notices that exist of that item.
 * \param Publication* list
 * \param int len
 * \param int* itemNumber
 * \param int* qPublications
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int report_qPublicationsPerItemNumber(Publication* list, int len,  int* itemNumber, int* qPublications);

/** \brief Enter a cuit through the console and print the number of warnings that exist for that client.
 * \param Publication* listPub
 * \param int lenPub
 * \param Customer* listCust
 * \param int lenCust
 * \param int* pubPerCust
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int report_qPublicationsPerCustomer(Publication* listPub, int lenPub, Customer* listCust, int lenCust, int* pubPerCust);

#endif /* REPORT_H_ */
