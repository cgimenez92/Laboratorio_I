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
#include <conio.h>
#include <ctype.h>
#include "customer.h"
#include "publication.h"
#include "menu.h"
#define ARRAY_SIZE 1000
#define ASC 1
#define DSC 0
#define ACTIVE 0
#define PAUSED 1

int main(void)
{
	setbuf(stdout, NULL);
	char seguir='s';
	int flagCustomer=0;
	int indexNewCustomer;
	int indexNewPublication;

	Customer listCustomers[ARRAY_SIZE];
	customer_init(listCustomers, ARRAY_SIZE);
	Publication listPublications[ARRAY_SIZE];
	publication_init(listPublications, ARRAY_SIZE);

	if(!customer_force_init(listCustomers, ARRAY_SIZE, "Cristian", "Gimenez", "20-35959517-1"))
		flagCustomer++;
	customer_force_init(listCustomers, ARRAY_SIZE, "Tito", "Puente", "20-36959517-3");
	customer_force_init(listCustomers, ARRAY_SIZE, "Cristian", "Jimeno", "20-35954517-1");
	customer_force_init(listCustomers, ARRAY_SIZE, "Alberto", "Terrrero", "20-35959584-1");
	customer_force_init(listCustomers, ARRAY_SIZE, "Homero", "Simpsons", "20-35959517-1");



	publication_force_init(listPublications, ARRAY_SIZE, 1, ACTIVE, 23, "Vendo moto");
	publication_force_init(listPublications, ARRAY_SIZE, 1, ACTIVE, 50, "Vendo celular");
	publication_force_init(listPublications, ARRAY_SIZE, 2, ACTIVE, 24, "Vendo computadora, buen estado");
	publication_force_init(listPublications, ARRAY_SIZE, 3, PAUSED, 23, "Pinto casas");
	publication_force_init(listPublications, ARRAY_SIZE, 5, ACTIVE, 14, "Alquilo casa en la playa");

	do
	{
		switch (menu())
		{
			case 1:
				indexNewCustomer = customer_create(listCustomers, ARRAY_SIZE);
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
					if(!customer_update(listCustomers, ARRAY_SIZE))
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
					if(!publication_deleteByIdCustomer(listPublications, ARRAY_SIZE, listCustomers, ARRAY_SIZE))
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

///////////***************Publicaciones***********************//////////////

			case 4:
				indexNewPublication = publication_create(listPublications, ARRAY_SIZE, listCustomers, ARRAY_SIZE);
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
					if(!publication_changeState(listPublications, ARRAY_SIZE, listCustomers, ARRAY_SIZE, PAUSED))
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
					if(!publication_changeState(listPublications, ARRAY_SIZE, listCustomers, ARRAY_SIZE, ACTIVE))
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

/////////////***************Print Clientes con Publicaciones***********************//////////////

			case 7:
				if(flagCustomer>0)
				{
					publication_countByCustomer(listPublications, ARRAY_SIZE, listCustomers, ARRAY_SIZE);
				}
				break;


/////////////***************Informes***********************//////////////
//


			case 9:
				seguir='n';
				break;

			default:
				printf("\nIngrese opcion correcta\n\n");
				break;
	        }
	         fflush(stdin);
		}while (seguir=='s');

	return 0;
}
