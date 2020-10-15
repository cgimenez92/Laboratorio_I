///*
// * publicaction.c
// *
// *  Created on: 11 oct. 2020
// *      Author: cgimenez
// */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"
#include "publication.h"
#include "customer.h"
#include "menu.h"

static int publication_newId              (void);
static int publication_swapPostionInArray (Publication* list, int positionToSwap);

static int publication_newId(void)
{
	static int id = 0;
	id = id+1;
	return id;
}

static int publication_swapPostionInArray (Publication* list, int positionToSwap)
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

int publication_force_init(Publication* list, int len, int idCustomer, int status, int itemNumber, char* text)
{
    int ret = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        i = publication_freePosition(list,len);
        if(i >= 0)
        {
        	list[i].id = publication_newId();
        	list[i].idCustomer = idCustomer;
        	list[i].isEmpty=FALSE;
        	list[i].status = status;
        	list[i].itemNumber = itemNumber;
        	strcpy(list[i].text, text);
        }
        ret = 0;
    }
    return ret;
}

int publication_init(Publication* list, int len)
{
	int ret = -1;
	if (list != NULL && len >0)
    {
		for (int i = 0; i<len; i++ )
		{
			list[i].isEmpty = TRUE;
		}
		ret = 0;
	}

	return ret;
}

int publication_print(Publication* list, int index)
{
	int ret = -1;

	if(list != NULL && index >= 0)
	{
		if(list[index].isEmpty==FALSE)
		{
			printf("ID de aviso: %d - Cliente: %d - Estado de la publicacion: %d - Rubro: %d - \nTexto aviso: %s\n", list[index].id, list[index].idCustomer, list[index].status, list[index].itemNumber, list[index].text);
			ret = 0;
		}else
		{
			printf("\n/****Error - No existe la publicacion****/\n");
		}
	}
	return ret;
}

int publication_printArray(Publication* list , int len)
{
	int ret = -1;
	if (list != NULL && len >0)
	{
		for (int i=0 ; i<len ; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("ID de aviso: %d - Cliente: %d - Estado de la publicacion: %d - Rubro: %d - \nTexto aviso: %s\n\n", list[i].id, list[i].idCustomer, list[i].status, list[i].itemNumber, list[i].text);
			}
		}
		ret = 0;
	}
return ret;
}

int publication_printArrayByIdCustomer(Publication* list , int len, int index)
{
	int ret = -1;
	if (list!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if(list[i].isEmpty==FALSE && list[i].idCustomer==index)
			{
				printf("ID de aviso: %d - Cliente: %d - Estado de la publicacion: %d - Rubro: %d - \nTexto aviso: %s\n", list[i].id, list[i].idCustomer, list[i].status, list[i].itemNumber, list[i].text);
				ret = 0;
			}
		}
	}
return ret;
}

int publication_create(Publication* listPub, int lenPub, Customer* listCust, int lenCust)
{
int ret = -1;
int index;
int indexCustomer;
Publication buffer;

	if (listPub!=NULL && lenPub>0 && listCust!=NULL && lenCust>0)
	{
		customer_printArray(listCust , lenCust);
		if (!publication_freePositionIndex (listPub, lenPub, &index) &&
			!getInt("Id de Cliente:", "Ingresar unicamente numeros", &buffer.idCustomer, 2, MIN_LIMIT_CLIENT, MAX_LIMIT_CLIENT) &&
			(indexCustomer=customer_searchId(listCust, lenCust, buffer.idCustomer))>=0)
		{
			if (listCust[indexCustomer+1].isEmpty == FALSE &&
				!getInt("Numero de Rubro:", "Ingresar unicamente numeros", &buffer.itemNumber, 2, MIN_LIMIT_ITEM_NUMBER, MAX_LIMIT_ITEM_NUMBER) &&
				!getString("Ingrese texto a publicar:", "\n/****Error - Superaste la cantidad de caracteres (64 - Max)****/\n", buffer.text, 2, LIMIT_TEXT))
				{
					listPub[index] = buffer;
					listPub[index].status = ACTIVE;
					listPub[index].id = publication_newId();
					listPub[index].isEmpty = FALSE;
					ret = index;
				}
				else
				{
					printf("\n/****Error - Finalizaron la cantidad de intentos****/\n");
				}
		}
		else
		{
			printf("\n/****Error - No se encuentran empleados****/\n");
		}
	}
	return ret;
}

int publication_changeState(Publication* listPub, int lenPub, Customer* listCust, int lenCust, int state)
{
	int ret = -1;
	char bufferChar;
	int indexCustomer;
	Publication buffer;

	if (listPub != NULL && lenPub>0)
	{
		publication_printArray(listPub,lenPub);
		if(!getInt("Id de publicacion:", "Ingresar unicamente numeros", &buffer.id, 2, MIN_LIMIT_PUBLICATION, MAX_LIMIT_PUBLICATION) &&
			(buffer.idCustomer = publication_searchIdCustomerById(listPub, lenPub, buffer.id)>=0) &&
			(indexCustomer=customer_searchId(listCust, lenCust, buffer.idCustomer))>=0)
		{
			customer_print(listCust, indexCustomer);
			if(listPub[indexCustomer+1].isEmpty == FALSE &&
			   !getYesOrNo("\n¿Continuar con el cambio de estado de la publicacion? - S/N", "\nEligio NO", "\n/****Error - Caracter invalido****/\n", &bufferChar, 2, 1))
			{
				for (int i=0 ; i<lenPub; i++)
				{
					if(buffer.id == listPub[i].id)
					{
						if(!state && listPub[i].status == PAUSED)
						{
							listPub[i].status = ACTIVE;
							ret = 0;
							break;
						}
						else if(state && listPub[i].status == ACTIVE)
							{
								listPub[i].status = PAUSED;
								ret = 0;
								break;
							}
					}
				}
			}
		}
	}
	return ret;
}

int publication_deleteByIdCustomer(Publication* listPub, int lenPub, Customer* listCust, int lenCust)
{
	int ret = -1;
	char bufferChar;
	int indexCustomer;
	Publication buffer;

	if (listPub != NULL && lenPub>0 && listCust != NULL && lenCust>0)
	{
		customer_printArray(listCust , lenCust);
		if(!getInt("Id de Cliente:", "Ingresar unicamente numeros", &buffer.idCustomer, 2, MIN_LIMIT_CLIENT, MAX_LIMIT_CLIENT) &&
			(indexCustomer=customer_searchId(listCust, lenCust, buffer.idCustomer))>=0)
		{
			publication_printArrayByIdCustomer(listPub, lenPub, indexCustomer+1);
			if(listCust[indexCustomer+1].isEmpty == FALSE &&
			   !getYesOrNo("\n¿Continuar con la eliminacion? - S/N", "\nEligio NO", "\n/****Error - Caracter invalido****/\n", &bufferChar, 2, 1))
			{
				for (int i=0 ; i<lenPub; i++)
				{
					if (buffer.idCustomer == listPub[i].idCustomer && buffer.idCustomer == listCust[i].id)
					{
						listPub[i].isEmpty = TRUE;
						listCust[i].isEmpty = TRUE;
						ret = 0;
					}
				}
			}
		}
	}
	return ret;
}

int publication_freePositionIndex(Publication* list, int len, int* pIndex)
{
	int ret = -1;
	int i;
		if (list != NULL && len >0 && pIndex != NULL)
        {
			for ( i = 0; i<len; i++)
			{
				if(list[i].isEmpty == TRUE)
				{
					*pIndex = i;
					ret = 0;
					break;
				}
			}
		}
	return ret;
}

int publication_freePosition(Publication* list, int len)
{
	int ret = -1;
	int i ;
		if (list != NULL && len>0)
        {
			for ( i = 0; i<len; i++)
            {
				if(list[i].isEmpty == TRUE)
				{
					ret = i;
					break;
				}
			}
		}
	return ret;
}

int publication_searchIdCustomerById(Publication* list, int len, int id)
{
    int ret = -1;
    int i;
    if (list!=NULL && len>0 && id>=0)
    {
        for (i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE && list[i].id == id)
            {
				ret=list[i].idCustomer;
				break;
            }
        }
    }
    else
    {
        printf("Error\n");
    }
    return ret;
}

int publication_sortArray(Publication* list, int len, int order)
{
	int ret = -1;
	int flagSwap;

	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		do
		{
			flagSwap = 0;
			for(int i=0; i<(len-1); i++)
			{
				if (order == 1 && ((list[i].idCustomer > list[i+1].idCustomer || //uno mayor que otro
								    list[i].idCustomer == list[i+1].idCustomer) && list[i].status > list[i+1].status))//iguales y otra variable para ordenar
				{
					publication_swapPostionInArray (list, i);
					flagSwap = 1;
				}
				else if (order == 0 && ((list[i].idCustomer < list[i+1].idCustomer || //uno mayor que otro
					    				 list[i].idCustomer == list[i+1].idCustomer) && list[i].status < list[i+1].status))//iguales y otra variable para ordenar
					{
						publication_swapPostionInArray (list, i);
						flagSwap = 1;
					}
			}
		}while(flagSwap);
		ret = 0;
	}
	return ret;
}

int publication_activePerCustomer(Publication* listPub, int lenPub, Customer* listCust, int lenCust)
{
	int ret = -1;
	int i;
	int j;
	int flagActivesAds=0;

	if(listPub!=NULL && lenPub>0 && listCust!=NULL && lenCust>0)
	{
		for(i=0; i<lenCust && listCust[i].isEmpty == FALSE; i++)
		{
			flagActivesAds = 0;
			for(j=0; j<lenPub; j++)
			{
				if(listPub[j].isEmpty == FALSE && listPub[j].status == ACTIVE && listPub[j].idCustomer == listCust[i].id)
				{
					flagActivesAds++;
				}
			}
			printf("ID: %d - Nombre: %s - Apellido: %s - Cantidad de avisos activos: %d\n\n", listCust[i].id, listCust[i].name, listCust[i].lastName, flagActivesAds);
		}
	}
	return ret;
}
