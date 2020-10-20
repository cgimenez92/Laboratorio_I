/*
 ============================================================================
 Name        : parcial_laboratorio_I.c
 Author      : cgimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"
#include "publication.h"
#include "controller.h"
#include "menu.h"
#include "report.h"

int main(void)
{
	setbuf(stdout, NULL);
	char resume='s';
	char resumeReports='s';
	int flagCustomer=0;
	int indexNewCustomer;
	int indexNewPublication;
	int bufferPublication;
	int bufferItemNumber;


	Customer listCustomers[ARRAY_SIZE_CUSTOMER];
	customer_init(listCustomers, ARRAY_SIZE_CUSTOMER);
	Publication listPublications[ARRAY_SIZE_ADS];
	publication_init(listPublications, ARRAY_SIZE_ADS);

	controller_force_init(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, &flagCustomer);

	do
	{
		switch (menu())
		{
											///////////***************CLIENTES***********************//////////////
			case 1:
				indexNewCustomer = customer_create(listCustomers, ARRAY_SIZE_CUSTOMER);
				if(indexNewCustomer)
				{
					customer_print(listCustomers, indexNewCustomer);
					flagCustomer++;
				}
				else
				{
					printf("\nNo se pudo crear el cliente");
				}
				break;

			case 2:
				if(flagCustomer>0)
				{
					if(!customer_update(listCustomers, ARRAY_SIZE_CUSTOMER))
					{
						printf("\nSe pudo modificar correctamente");
					}
					else
					{
						printf("\nNo se pudo modificar");
					}
				}
				else
				{
					printf("\nNo se ingreso ningun cliente\n");
				}
				break;

			case 3:
				if(flagCustomer>0)
				{
					if(!publication_deleteByIdCustomer(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER))
					{
						printf("\nSe borro cliente correctamente");
					}
					else
					{
						printf("\nNo se pudo borrar cliente\n");
					}
				}
				else
				{
					printf("\nNo se ingreso ningun cliente\n");
				}

				break;

											///////////***************PUBLICACIONES***********************//////////////

			case 4:
				indexNewPublication = publication_create(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER);
				if(indexNewPublication)
				{
					publication_print(listPublications, indexNewPublication);
				}
				else
				{
					printf("\nNo se pudo crear la publicacion");
				}
				break;
			case 5:
				if(flagCustomer>0)
				{
					if(!publication_changeState(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, PAUSED))
					{
						printf("\nSe pudo modificar correctamente");
					}
					else
					{
						printf("\nNo se pudo modificar");
					}
				}
				else
				{
					printf("\nNo se ingreso ningun Cliente\n");
				}
				break;
			case 6:
				if(flagCustomer>0)
				{
					if(!publication_changeState(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, ACTIVE))
					{
						printf("\nSe pudo modificar correctamente");
					}
					else
					{
						printf("\nNo se pudo modificar");
					}
				}
				else
				{
					printf("\nNo se ingreso ningun Cliente\n");
				}
				break;

									/////////////***************PRINT CLIENTES CON PUBLICACIONES***********************//////////////
			case 7:
				if(flagCustomer>0)
				{
					publication_activePerCustomer(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER);
				}
				break;


									/////////////***************************INFORMES**********************************//////////////
			case 8:
				do
				{
					switch (menuReports())
					{
					case 1:
						if(flagCustomer>0)
						{
							report_customerCountPublications(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, ALL_MAX);
						}
						break;
					case 2:
						if(flagCustomer>0)
						{
							report_qPublicationsPaused(listPublications, ARRAY_SIZE_ADS);
						}
						break;
					case 3:
						if(flagCustomer>0)
						{
							report_itemNumberWithMorePublications(listPublications, ARRAY_SIZE_ADS);
						}
						break;
					case 4:
						if(flagCustomer>0)
						{
							report_customerCountPublications(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, ACTIVE);
						}
						break;
					case 5:
						if(flagCustomer>0)
						{
							report_customerCountPublications(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, PAUSED);
						}
						break;
					case 6:
						if(flagCustomer>0)
						{
							report_sortArrayByItemNumber(listPublications, ARRAY_SIZE_ADS);
						}
						break;
					case 7:
						if(flagCustomer>0)
						{
							report_qPublications(listPublications, ARRAY_SIZE_ADS, &bufferPublication);
						}
						break;
					case 8:
						if(flagCustomer>0)
						{
							report_customerCountPublications(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, ALL_MIN);
						}
						break;
					case 9:
						if(flagCustomer>0)
						{
							report_qPublicationsPerItemNumber(listPublications, ARRAY_SIZE_ADS,  &bufferItemNumber, &bufferPublication);
						}
						break;

					case 10:
						if(flagCustomer>0)
						{
							report_qPublicationsPerCustomer(listPublications, ARRAY_SIZE_ADS, listCustomers, ARRAY_SIZE_CUSTOMER, &bufferPublication);
						}
						break;
					case 11:
						resumeReports='n';
						break;
					}
				}while (resumeReports=='s');
				break;

			case 9:
				resume='n';
				break;

			default:
				printf("\nIngrese opcion correcta\n\n");
				break;
	        }
	         fflush(stdin);
		}while (resume=='s');

	return 0;
}
