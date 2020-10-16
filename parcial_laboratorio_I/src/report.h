///*
// * reports.h
// *
// *  Created on: 12 oct. 2020
// *      Author: cgimenez
// */

#ifndef REPORT_H_
#define REPORT_H_

/** \brief Crosses the arrays of the entities and it acquires the one that has more publications
 * \param Publication* listPub
 * \param int lenPub
 * \param Customer* listCust
 * \param int lenCust
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int report_customerWithMorePublications(Publication* listPub, int lenPub, Customer* listCust, int lenCust, int statusPublication);

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



int report_countPublications(Publication* listPub, int lenPub, int idCustomer, int* qPublications,  int* qPublicationsActives,  int* qPublicationsPaused);

#endif /* REPORT_H_ */
