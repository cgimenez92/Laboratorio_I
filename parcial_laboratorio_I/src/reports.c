///*
// * reports.c
// *
// *  Created on: 12 oct. 2020
// *      Author: cgimenez
// */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "gets.h"
#include "publication.h"
#include "customer.h"
#include "menu.h"

int report_customerWithMorePublications(Publication* listPub, int lenPub, Customer* listCust, int lenCust)
{
	int ret = -1;
	int flagActivesItems;
	int indexCustomer;
	int i=0;

	if(listPub!=NULL && lenPub>0 && listCust!=NULL && lenCust>0)
	{
		publication_sortArray(listPub, lenPub, ASC);
		for(;i<lenPub && listPub[i].isEmpty == FALSE; i++)
		{
			if(listPub[i].idCustomer != listPub[i-1].idCustomer)
			{
				flagActivesItems=1;
				for(int j=i+1; j<lenPub && listPub[i].idCustomer == listPub[j].idCustomer; j++)
				{
					flagActivesItems++;
				}
					indexCustomer=customer_searchId(listCust, lenCust, listPub[i].idCustomer);
					if(indexCustomer>=0)
					{
						customer_print(listCust, indexCustomer);
						printf(" Cantidad de Publicaciones %d\n", flagActivesItems);
						break;
					}
			}
			else
			{
				continue;
			}
		}
		ret = 0;
	}
	return ret;
}
