///*
// * reports.h
// *
// *  Created on: 12 oct. 2020
// *      Author: cgimenez
// */

#ifndef REPORT_H_
#define REPORT_H_

int report_customerWithMorePublications(Publication* listPub, int lenPub, Customer* listCust, int lenCust);
int report_qPublicationsPaused          (Publication* list, int len);
int report_itemNumberWithMorePublications(Publication* list, int len);

#endif /* REPORT_H_ */
