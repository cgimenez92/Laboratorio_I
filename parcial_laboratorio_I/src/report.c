///*
// * reports.c
// *
// *  Created on: 12 oct. 2020
// *      Author: cgimenez
// */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"
#include "publication.h"
#include "customer.h"


/** \brief list the units on the entity and acquires the one that has more.
 * \param int i
 * \param int* unit
 * \param int* index
 * \param int flag
 * \param int* max
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
static int swapMaxEntity(int i, int* unit, int* index, int flag, int* max);

static int swapMaxEntity(int i, int* unit, int* index, int flag, int* max)
{
	int ret = -1;
	if(unit!=NULL || index!=NULL ||  max!=NULL)
	{
		if(!i)
		{
			*unit=flag;
			*max=flag;
			*index=i;
		}
		else if(*unit > *max)
			{
				*max=*unit;
				*index= i;
				ret = 0;
			}
	}
	return ret;
}

int report_customerWithMorePublications(Publication* listPub, int lenPub, Customer* listCust, int lenCust)
{
	int ret = -1;
	int customerWithMorePublications;
	int PublicationsPerCustomer;
	int indexCustomerMorePublications;
	int flagsPublications=0;

	if(listPub!=NULL && lenPub>0 && listCust!=NULL && lenCust>0)
	{
		for(int i=0; i<lenCust; i++)
		{
			for(int j=0; j<lenPub; j++)
			{
				if(listPub[j].isEmpty == FALSE && listPub[j].idCustomer == listCust[i].id)
				{
					flagsPublications++;
				}
			}
			swapMaxEntity(i, &PublicationsPerCustomer, &indexCustomerMorePublications, flagsPublications, &customerWithMorePublications);
			ret=0;
		}
        printf("********************************************************************\n");
        printf("********************* CLIENTE CON MAS AVISOS ***********************\n");
        printf("********************************************************************\n");
		printf("ID: %d - Nombre: %s - Apellido: %s - Cantidad de avisos: %d\n", listCust[indexCustomerMorePublications].id, listCust[indexCustomerMorePublications].name, listCust[indexCustomerMorePublications].lastName, customerWithMorePublications);
		printf("********************************************************************\n");
	}
	return ret;
}

int report_qPublicationsPaused(Publication* list, int len)
{
	int ret = -1;
	int flagPausedPublications=0;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].status == PAUSED)
			{
				flagPausedPublications++;
			}
			ret = 0;
		}
	}
	publication_printArray(list ,len);
    printf("******************************************************************\n");
    printf("**************** CANTIDAD DE AVISOS PAUSADOS: %d *****************\n", flagPausedPublications);
    printf("******************************************************************\n");
	printf("******************************************************************\n");
	return ret;
}

int report_itemNumberWithMorePublications(Publication* list, int len)
{
	int ret = -1;
	int customerWithMorePublications;
	int PublicationsPerCustomer;
	int indexCustomerMorePublications;
	int flagItemNumbers=0;

	if(list!=NULL && len>0)
	{
		for(int i=0; i<len && list[i].isEmpty == FALSE; i++)
		{
			flagItemNumbers = 0;
			for(int j=0; j<len; j++)
			{
				if(list[i].isEmpty == FALSE && list[i].itemNumber == list[j].itemNumber)
				{
					flagItemNumbers++;
				}
			}

			swapMaxEntity(i, &PublicationsPerCustomer, &indexCustomerMorePublications, flagItemNumbers, &customerWithMorePublications);
			ret=0;
		}
        printf("***************************************************************\n");
        printf("******************** RUBRO CON MAS AVISOS *********************\n");
        printf("***************************************************************\n");
		printf("************ ID: %d - Cantidad de publicaciones: %d ***********\n", list[indexCustomerMorePublications].itemNumber, PublicationsPerCustomer);
		printf("***************************************************************\n");
	}
	return ret;
}




