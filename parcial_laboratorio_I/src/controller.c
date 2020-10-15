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
	publication_force_init(listPub, lenPub, 1, ACTIVE, 23, "Vendo moto");
	publication_force_init(listPub, lenPub, 5, ACTIVE, 50, "Vendo celular");
	publication_force_init(listPub, lenPub, 2, ACTIVE, 24, "Vendo computadora, buen estado");
	publication_force_init(listPub, lenPub, 1, ACTIVE, 23, "Pinto casas");
	publication_force_init(listPub, lenPub, 2, ACTIVE, 24, "Alquilo casa en la playa");

	if(!customer_force_init(listCust, lenCust, "Cristian", "Gimenez", "20-35959517-1"))
		*flag=*flag+1;
	customer_force_init(listCust, lenCust, "Tito",     "Puente",   "20-36959517-3");
	customer_force_init(listCust, lenCust, "Cristian", "Jimeno",   "20-35954517-1");
	customer_force_init(listCust, lenCust, "Alberto",  "Terrrero", "20-35959584-1");
	customer_force_init(listCust, lenCust, "Homero",   "Simpsons", "20-35959517-1");
}
