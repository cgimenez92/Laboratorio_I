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

static int publication_newId (void);
static int publication_swapPostionInArray (Publication* list, int positionToSwap);

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

static int publication_newId(void)
{
	static int id = 0;
	id = id+1;
	return id;
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

int publication_create(Publication* listPub, int lenPub, Customer* listCust, int lenCust)
{
int ret = -1;
int index;
int indexCustomer;
Publication buffer;

	if (listPub!=NULL && lenPub>0 && listCust!=NULL && lenCust>0)
	{
		if (!publication_freePositionIndex (listPub, lenPub, &index) &&
			!getInt("Id de Cliente:", "Ingresar unicamente numeros", &buffer.idCustomer, 2, MIN_LIMIT_SECTOR, MAX_LIMIT_SECTOR) &&
			(indexCustomer=customer_searchId(listCust, lenCust, buffer.idCustomer))>=0)
		{
			if (listCust[indexCustomer+1].isEmpty == FALSE &&
				!getInt("Numero de Rubro:", "Ingresar unicamente numeros", &buffer.itemNumber, 2, MIN_LIMIT_SECTOR, MAX_LIMIT_SECTOR) &&
				!getString("Ingrese texto a publicar:", "\n/****Error - Superaste la cantidad de caracteres (64 - Max)****/\n", buffer.text, 2, MAX_LIMIT_TEXT))
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
//
//int publication_update(Publication* list, int len)
//{
//	int ret = -1;
//	int aux;
//	int auxIndex;
//	char auxMenu='s';
//	Publication buffer;
//
//	if(list != NULL && len > 0)
//	{
//		publication_printArray(list, len);
//		if(!getInt("Ingrese el id del usuario que desea cambiar: ", "Ingresar unicamente numeros", &aux, 2, 1, 1000))
//		{
//			auxIndex=publication_searchId(list, len, aux);
//			if(list[auxIndex].isEmpty==FALSE)
//			{
//				publication_print(list,auxIndex);
//				buffer = list[auxIndex];
//				do
//				{
//					switch (menuChangeParameter())
//					{
//						case 1:
//							if(!getName ("Ingrese nombre", "Ingresar unicamente caracteres", buffer.name, 3, STRING_SIZE))
//							{
//								strncpy(list[auxIndex].name , buffer.name,STRING_SIZE);
//							}
//							break;
//						case 2:
//							if(!getName ("Ingrese Apellido", "Ingresar unicamente caracteres", buffer.lastName, 3, STRING_SIZE))
//							{
//								strncpy(list[auxIndex].lastName , buffer.lastName,STRING_SIZE);
//							}
//							break;
//						case 3:
//							if(!getFloat("Ingrese Remuneracion: ", "Ingresar unicamente numeros separados por (.) -> Ej: 100.00", &buffer.salary, 2, MIN_LIMIT_SALARY, MAX_LIMIT_SALARY) )
//							{
//								list[auxIndex].salary = buffer.salary;
//							}
//							break;
//						case 4:
//							if(!getInt("Sector: ", "Ingresar unicamente numeros", &buffer.sector, 2, MIN_LIMIT_SECTOR, MAX_LIMIT_SECTOR))
//							{
//								list[auxIndex].sector = buffer.sector;
//							}
//							break;
//						case 5:
//							auxMenu='n';
//							break;
//
//						default:
//							printf("\nIngrese opcion correcta\n\n");
//							break;
//					}
//				}while (auxMenu=='s');
//				publication_print(list,auxIndex);
//				ret = 0;
//			}
//		}
//		else
//			{
//				printf("\n/****Error - No se encuentran datos del Id ingresado****/\n");
//			}
//	}
//	return ret;
//}
//
//

int publication_deleteByIdCustomer(Publication* listPub, int lenPub, Customer* listCust, int lenCust)
{
	int ret = -1;
	char bufferChar;
	int indexCustomer;
	Publication buffer;

	if (listPub != NULL && lenPub>0)
	{
		if(!getInt("Id de Cliente:", "Ingresar unicamente numeros", &buffer.idCustomer, 2, MIN_LIMIT_SECTOR, MAX_LIMIT_SECTOR) &&
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

int publication_changeState(Publication* listPub, int lenPub, Customer* listCust, int lenCust, int state)
{
	int ret = -1;
	char bufferChar;
	int indexCustomer;
	Publication buffer;

	if (listPub != NULL && lenPub>0)
	{
		publication_printArray(listPub,lenPub);
		if(!getInt("Id de publicacion:", "Ingresar unicamente numeros", &buffer.id, 2, MIN_LIMIT_SECTOR, MAX_LIMIT_SECTOR) &&
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
						if(!state)
						{
							listPub[i].status = ACTIVE;
							ret = 0;
							break;

						}
						else
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
//

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

int publication_countByCustomer(Publication* listPub, int lenPub, Customer* listCust, int lenCust)
{
	int ret = -1;
	int flagActivesItems;
	int indexCustomer;
	int i=0;

	if(listPub!=NULL && lenPub>0 && listCust!=NULL && lenCust>0)
	{
		publication_sortArray(listPub, lenPub, ASC);
		for(;i<lenPub && listPub[i].isEmpty == FALSE && listPub[i].status == ACTIVE; i++)
		{
			if(listPub[i].idCustomer != listPub[i-1].idCustomer)
			{
				flagActivesItems=1;
				for(int j=i+1; j<lenPub && listPub[i].idCustomer == listPub[j].idCustomer && listPub[j].status == ACTIVE; j++)
				{
					flagActivesItems++;
				}
					indexCustomer=customer_searchId(listCust, lenCust, listPub[i].idCustomer);
					if(indexCustomer>=0)
					{
						customer_print(listCust, indexCustomer);
						printf(" Q Publicaciones activas %d\n", flagActivesItems);
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
