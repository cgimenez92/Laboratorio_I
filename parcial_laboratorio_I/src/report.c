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
static int swap(int i, int* index, int* flag, int* max);

static int swapMaxEntity(int i, int* unit, int* index, int flag, int* max)
{
	int ret = -1;
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
	return ret;
}

static int swap(int i, int* index, int* flag, int* max)
{
	int ret = -1;

	if(!i || *flag > *max)
	{
		*max=*flag;
		*index=i;
		ret = 0;
	}
	return ret;
}

int report_countPublications(Publication* listPub, int lenPub, int idCustomer, int* qPublications,  int* qPublicationsActives,  int* qPublicationsPaused)
{
	int ret = -1;
	int flagsPublications=0;
	int flagsPublicationsActives=0;
	int flagsPublicationsPaused=0;

	if(listPub!=NULL && lenPub>0 && qPublications!=NULL && idCustomer>0)
	{
		for(int i=0; i<lenPub; i++)
		{
			if(listPub[i].isEmpty == FALSE && listPub[i].idCustomer == idCustomer)
			{
				flagsPublications++;
				if(listPub[i].status == PAUSED)
				{
					flagsPublicationsPaused++;
				}
				if(listPub[i].status == ACTIVE)
				{
					flagsPublicationsActives++;
				}
			}
		}
		*qPublications =flagsPublications;
		*qPublicationsActives =flagsPublicationsActives;
		*qPublicationsPaused =flagsPublicationsPaused;
		ret=0;
	}
	return ret;
}

int report_customerWithMorePublications(Publication* listPub, int lenPub, Customer* listCust, int lenCust, int statusPublication)
{
	int ret = -1;
	int qPublications;
	int qPublicationsActives;
	int qPublicationsPaused;
	int bufferPublications;
	int indexCustomerMorePublications;

	if(listPub!=NULL && lenPub>0 && listCust!=NULL && lenCust>0)
	{
		for(int i=0; i<lenCust; i++)
		{
			if(!report_countPublications(listPub, lenPub, listCust[i].id, &qPublications, &qPublicationsActives, &qPublicationsPaused))
			{
				switch (statusPublication)
				{
				case 0:
					swap(i, &indexCustomerMorePublications, &qPublicationsActives, &bufferPublications);
					break;
				case 1:
					swap(i, &indexCustomerMorePublications, &qPublicationsPaused, &bufferPublications);
					break;
				case 2:
					swap(i, &indexCustomerMorePublications, &qPublications, &bufferPublications);
					break;
				}
				ret = 0;
			}
		}
        printf("********************************************************************\n");
		printf("ID: %d - Nombre: %s - Apellido: %s - Cantidad de avisos: %d\n", listCust[indexCustomerMorePublications].id, listCust[indexCustomerMorePublications].name, listCust[indexCustomerMorePublications].lastName, bufferPublications);
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

/* d) Imprimir lista de rubros ordenados de menor a mayor (sin repetir) */



/* e) Cantidad de avisos activos totales */
int report_qPublications(Publication* listPub, int lenPub, int* qPublications)
{
	int ret = -1;
	int flagsPublications=0;

	if(listPub!=NULL && lenPub>0 && qPublications!=NULL)
	{
		for(int i=0; i<lenPub; i++)
		{
			if(listPub[i].isEmpty == FALSE && listPub[i].status == ACTIVE)
			{
				flagsPublications++;
			}
		}
		*qPublications =flagsPublications;
		ret=0;
		printf("***************************************************************\n");
		printf("************ CANTIDAD DE AVISOS ACTIVOS TOTALES: %d ***********\n", *qPublications);
		printf("***************************************************************\n");
	}
	return ret;
}
/* f) Cliente con menos avisos */


/* g) Cantidad por rubro: Ingresar por consola un numero de rubro e imprimir la cantidad de avisos que existen de dicho rubro. */
int report_qPublicationsPerItemNumber(Publication* list, int len,  int itemNumber, int* qPublications)
{
	int ret = -1;
	int flagsPublications=0;
	int i;

	if(!getInt("Ingresar rubro a calcular la cantidad que hay en avisos:  \n", "Ingresar unicamente numeros", &itemNumber, 2, 1, 69))
	{
		if(list!=NULL && len>0)
		{
			for(i=0; i<len; i++)
			{
				if(list[i].isEmpty == FALSE && list[i].itemNumber == itemNumber)
				{
					flagsPublications++;
				}
				/*else if(list[i].itemNumber != itemNumber)
					{
						printf("***************** EL RUBRO NO EXISTE ****************\n");
						ret=-2;
					}*/
			}
			*qPublications=flagsPublications;
			ret = 0;
		    printf("*******************************************************************\n");
		    printf("***************** CANTIDAD DE AVISOS POR RUBRO: %d ****************\n", *qPublications);
		    printf("*******************************************************************\n");
			printf("*******************************************************************\n");
		}
	}
	publication_printArray(list ,len);

	return ret;
}

/* h) Cantidad por cliente: Ingresar por consola un cuit e imprimir la cantidad de avisos que existen de dicho cliente. */
int report_qPublicationsPerCustomer(Publication* listPub, int lenPub, Customer* listCust, int lenCust, char* cuit, int* pubPerCust)
{
	int ret=-1;
	int i;
	int qPublications;
	int qPublicationsActives;
	int qPublicationsPaused;
	int flagsPublications=0;
	int indexCustomerMorePublications;

	if(!getCuit ("Ingrese CUIT: ",
				 "\n/****Error - Ingresar cuit con el siguiente formato -> Ej: xx-xxxxxxxx-x****/\n",
				 "\n/****Error - Caracteres invalidos****/\n/****Caracteres validos -> [0 - 9]****/\n",
				 cuit, 2, CUIT_SIZE))
	{
		if(listPub!=NULL && lenPub>0 && listCust!=NULL && lenCust>0)
		{
			for(i=0; i<lenCust; i++)
			{
				if(!report_countPublications(listPub, lenPub, listCust[i].id, &qPublications, &qPublicationsActives, &qPublicationsPaused) &&
					!strnicmp(listCust[i].cuit, cuit, CUIT_SIZE))
				{
					flagsPublications++;
				}
			}
			indexCustomerMorePublications = i;
			*pubPerCust=flagsPublications;
			ret = 0;
			printf("********************************************************************\n");
			printf("ID: %d - Nombre: %s - Apellido: %s - Cantidad de avisos: %d\n", listCust[indexCustomerMorePublications].id, listCust[indexCustomerMorePublications].name, listCust[indexCustomerMorePublications].lastName, *pubPerCust);
			printf("********************************************************************\n");
		}
	}
	return ret;
}
