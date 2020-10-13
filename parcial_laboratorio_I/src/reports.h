///*
// * reports.h
// *
// *  Created on: 12 oct. 2020
// *      Author: cgimenez
// */

#ifndef REPORTS_H_
#define REPORTS_H_

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

int report_customerWithMorePublications(Publication* listPub, int lenPub, Customer* listCust, int lenCust);

#endif /* REPORTS_H_ */
