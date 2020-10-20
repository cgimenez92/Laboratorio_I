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

static int report_swapPostionInArray (Publication* list, int positionToSwap);
static int report_printDistinctItemNumber(Publication* list , int len);
static int swapMax(int i, int* index, int* flag, int* max);
static int swapMin(int i, int* index, int* flag, int* min);

static int swapMin(int i, int* index, int* flag, int* min)
{
	int ret = -1;
	if(!i || *flag < *min)
	{
		*min=*flag;
		*index=i;
		ret = 0;
	}
	return ret;
}

static int swapMax(int i, int* index, int* flag, int* max)
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

/*1-Cliente con mas avisos // 4-Cliente con mas avisos activos // 5-Cliente con mas avisos pausados // 8-Clientes con menos avisos*/
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

int report_customerCountPublications(Publication* listPub, int lenPub, Customer* listCust, int lenCust, int statusPublication)
{
	int ret = -1;
	int qPublications;
	int qPublicationsActives;
	int qPublicationsPaused;
	int bufferPublications;
	int indexCustomerCountPublications;

	if(listPub!=NULL && lenPub>0 && listCust!=NULL && lenCust>0)
	{
		for(int i=0; i<lenCust; i++)
		{
			if(!report_countPublications(listPub, lenPub, listCust[i].id, &qPublications, &qPublicationsActives, &qPublicationsPaused) && listPub[i].isEmpty == FALSE)
			{
				switch (statusPublication)
				{
				case 0:
					swapMax(i, &indexCustomerCountPublications, &qPublicationsActives, &bufferPublications);
					break;
				case 1:
					swapMax(i, &indexCustomerCountPublications, &qPublicationsPaused, &bufferPublications);
					break;
				case 2:
					swapMax(i, &indexCustomerCountPublications, &qPublications, &bufferPublications);
					break;
				case 3:
					swapMin(i, &indexCustomerCountPublications, &qPublications, &bufferPublications);
					break;
				}
				ret = 0;
			}
		}
        printf("********************************************************************\n");
		printf("ID: %d - Nombre: %s - Apellido: %s - Cantidad de avisos: %d\n", listCust[indexCustomerCountPublications].id, listCust[indexCustomerCountPublications].name, listCust[indexCustomerCountPublications].lastName, bufferPublications);
		printf("********************************************************************\n");
	}
	return ret;
}

/*2-Cantidad de avisos pausados*/
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

/*3-Rubro con mas avisos*/
int report_itemNumberWithMorePublications(Publication* list, int len)
{
	int ret = -1;
	int customerWithMorePublications;
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
			swapMax(i, &indexCustomerMorePublications, &flagItemNumbers, &customerWithMorePublications);
			ret=0;
		}
        printf("***************************************************************\n");
        printf("******************** RUBRO CON MAS AVISOS *********************\n");
        printf("***************************************************************\n");
		printf("************ ID: %d - Cantidad de publicaciones: %d ***********\n", list[indexCustomerMorePublications].itemNumber, customerWithMorePublications);
		printf("***************************************************************\n");
	}
	return ret;
}

/* 6-Imprimir lista de rubros ordenados de menor a mayor (sin repetir) */
static int report_swapPostionInArray (Publication* list, int positionToSwap)
{
	int ret = -1;
	Publication buffer;

	if(list != NULL && positionToSwap >= 0)
	{
		ret = 0;
		buffer = list[positionToSwap];
		list[positionToSwap] = list[positionToSwap+1];
		list[positionToSwap+1] = buffer;
	}

	return ret;
}

static int report_printDistinctItemNumber(Publication* list , int len)
{
	int ret = -1;
	if (list != NULL && len >0)
	{
		for (int i=0 ; i<len ; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].itemNumber != list[i+1].itemNumber)
			{
				printf("Rubro: %d\n", list[i].itemNumber);
			}
		}
		ret = 0;
	}
return ret;
}

int report_sortArrayByItemNumber(Publication* list, int len)
{
	int ret = -1;
	int flagSwap;

	if(list != NULL && len > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i=0; i<(len-1); i++)
			{
				if (list[i].itemNumber < list[i+1].itemNumber)
				{
					report_swapPostionInArray (list, i);
					flagSwap = 1;
				}
			}
		}while(flagSwap);
		report_printDistinctItemNumber(list , len);
		ret = 0;
	}
	return ret;
}

/*7-Cantidad de avisos activos totales */
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
		printf("************ CANTIDAD DE AVISOS ACTIVOS TOTALES: %d ***********\n", flagsPublications);
		printf("***************************************************************\n");
	}
	return ret;
}

/*9-Cantidad por rubro: Ingresar por consola un numero de rubro e imprimir la cantidad de avisos que existen de dicho rubro. */
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
		    printf("***************** CANTIDAD DE AVISOS POR RUBRO: %d ****************\n", flagsPublications);
		    printf("*******************************************************************\n");
			printf("*******************************************************************\n");
		}
	}
	publication_printArray(list ,len);

	return ret;
}

///Error cuando pongo un cuit ok y luego pongo uno erroneo////
/*10-Cantidad por cliente: Ingresar por consola un cuit e imprimir la cantidad de avisos que existen de dicho cliente. */
int report_qPublicationsPerCustomer(Publication* listPub, int lenPub, Customer* listCust, int lenCust, int* pubPerCust)
{
	int ret=-1;
	int qPublications;
	int qPublicationsActives;
	int qPublicationsPaused;
	char bufferCuit[CUIT_SIZE];
	int indexCustomerMorePublications;

	if(!getCuit ("Ingrese CUIT: ",
				 "\n/****Error - Ingresar cuit con el siguiente formato -> Ej: xx-xxxxxxxx-x****/\n",
				 "\n/****Error - Caracteres invalidos****/\n/****Caracteres validos -> [0 - 9]****/\n",
				 bufferCuit, 2, CUIT_SIZE))
	{

		if(listPub!=NULL && lenPub>0 && listCust!=NULL && lenCust>0)
		{
			for(int i=0; i<lenCust; i++)
			{
				if(strnicmp(listCust[i].cuit, bufferCuit, CUIT_SIZE)==0 &&
				   !report_countPublications(listPub, lenPub, listCust[i].id, &qPublications, &qPublicationsActives, &qPublicationsPaused))
				{
					indexCustomerMorePublications = i;
					*pubPerCust=qPublications;
					ret = 0;
				}
			}
			printf("********************************************************************\n");
			printf("ID: %d - Nombre: %s - Apellido: %s - Cantidad de avisos: %d\n", listCust[indexCustomerMorePublications].id, listCust[indexCustomerMorePublications].name, listCust[indexCustomerMorePublications].lastName, qPublications);
			printf("********************************************************************\n");
		}
	}
	return ret;
}
