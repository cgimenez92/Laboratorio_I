/*
 * controller.c
 *
 *  Created on: 14 oct. 2020
 *      Author: cgimenez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "publication.h"
#include "customer.h"
#include "menu.h"


void controller_force_init(Publication* listPub, int lenPub, Customer* listCust, int lenCust, int* flag)
{
	publication_force_init(listPub, lenPub, 2, PAUSED, 23, "Vendo moto");
	publication_force_init(listPub, lenPub, 5, ACTIVE, 50, "Vendo celular");
	publication_force_init(listPub, lenPub, 2, ACTIVE, 24, "Vendo computadora, buen estado");
	publication_force_init(listPub, lenPub, 1, ACTIVE, 23, "Pinto casas");
	publication_force_init(listPub, lenPub, 2, PAUSED, 2, "Alquilo casa en la playa");
	publication_force_init(listPub, lenPub, 1, ACTIVE, 23, "Vendo moto");
	publication_force_init(listPub, lenPub, 5, ACTIVE, 50, "Vendo celular");
	publication_force_init(listPub, lenPub, 2, PAUSED, 24, "Vendo computadora, buen estado");
	publication_force_init(listPub, lenPub, 1, ACTIVE, 24, "Pinto casas");
	publication_force_init(listPub, lenPub, 2, ACTIVE, 2, "Alquilo casa en la playa");

	if(!customer_force_init(listCust, lenCust, "Cristian", "Gimenez", "20-36918628-1"))
	{
		*flag=*flag+1;
	}
	customer_force_init(listCust, lenCust, "Roberto",  "Puente",   	"20-36959517-3");
	customer_force_init(listCust, lenCust, "Cristian", "Gomez",   	"20-35954515-1");
	customer_force_init(listCust, lenCust, "Alberto",  "Terrrero", 	"20-35959584-1");
	customer_force_init(listCust, lenCust, "Homero",   "Jimeno", 	"20-35549556-1");
	customer_force_init(listCust, lenCust, "Marcos",   "Aguirre",   "20-36152518-9");
	customer_force_init(listCust, lenCust, "Jimena",   "Gonzalez",  "20-84564816-3");
	customer_force_init(listCust, lenCust, "Alberto",  "Zapata",	"20-36532565-2");
}
