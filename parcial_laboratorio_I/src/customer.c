/*
 * customer.c
 *
 *  Created on: 11 oct. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"
#include "customer.h"
#include "menu.h"

static int customer_newId (void);

static int customer_newId(void)
{
	static int id = 0;
	id = id+1;
	return id;
}

int customer_force_init(Customer* list, int len, char* name, char* lastName, char* cuit)
{
    int ret = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        i = customer_freePosition(list,len);
        if(i >= 0)
        {
        	list[i].id=customer_newId();
        	list[i].isEmpty=FALSE;
        	strncpy(list[i].name,name,STRING_SIZE);
			strncpy(list[i].lastName,lastName,STRING_SIZE);
			strncpy(list[i].cuit,cuit,STRING_SIZE);
        }
        ret = 0;
    }
    return ret;
}

int customer_init(Customer* list, int len)
{
	int ret = -1;
	if (list != NULL && len >0)
    {
		for (int i = 0; i<len; i++ )
		{
			list[i].isEmpty=TRUE;
		}
		ret = 0;
	}

	return ret;
}

int customer_create(Customer* list, int len)
{
int ret = -1;
int index;
Customer buffer;

	if (list != NULL && len >0)
	{
		if (!customer_freePositionIndex (list, len, &index))
		{
			if (!getName ("Ingrese nombre:", "Ingresar unicamente caracteres", buffer.name, 3, STRING_SIZE) &&
				!getName ("Ingrese Apellido:", "Ingresar unicamente caracteres", buffer.lastName, 3, STRING_SIZE) &&
				!getCuit ("Ingrese CUIT: ",
					     "\n/****Error - Ingresar cuit con el siguiente formato -> Ej: xx-xxxxxxxx-x****/\n",
					     "\n/****Error - Caracteres invalidos****/\n/****Caracteres validos -> [0 - 9]****/\n",
						 buffer.cuit, 2, CUIT_SIZE))
			{
				list[index]=buffer;
				list[index].id=customer_newId();
				list[index].isEmpty=FALSE;
				ret = index;
			}
			else
				{
					printf("\n/****Error - Finalizaron la cantidad de intentos****/\n");
				}
		}
		else
			{
				printf("\n/****Error - No se encuentran espacios disponibles en el listado de clientes****/\n");
			}
	}
	return ret;
}


int customer_update(Customer* list, int len)
{
	int ret = -1;
	int aux;
	int auxIndex;
	char auxMenu='s';
	Customer buffer;

	if(list != NULL && len > 0)
	{
		customer_printArray(list, len);
		if(!getInt("Ingrese el id del usuario que desea cambiar: ", "Ingresar unicamente numeros", &aux, 2, 1, 1000))
		{
			auxIndex=customer_searchId(list, len, aux);
			if(list[auxIndex].isEmpty==FALSE)
			{
				customer_print(list,auxIndex);
				buffer = list[auxIndex];
				do
				{
					switch (menuChangeParameter())
					{
						case 1:
							if(!getName ("Ingrese nombre", "Ingresar unicamente caracteres", buffer.name, 3, STRING_SIZE))
							{
								strncpy(list[auxIndex].name , buffer.name,STRING_SIZE);
							}
							break;
						case 2:
							if(!getName ("Ingrese Apellido", "Ingresar unicamente caracteres", buffer.lastName, 3, STRING_SIZE))
							{
								strncpy(list[auxIndex].lastName , buffer.lastName,STRING_SIZE);
							}
							break;
						case 3:
							if(!getCuit("Ingrese CUIT: ",
									   "\n/****Error - Ingresar cuit con el siguiente formato -> Ej: xx-xxxxxxxx-x****/\n",
									   "\n/****Error - Caracteres invalidos****/\n/****Caracteres validos -> [0 - 9]****/\n",
										buffer.cuit, 2, CUIT_SIZE))
							{
								strncpy(list[auxIndex].cuit, buffer.cuit, CUIT_SIZE);
							}
							break;
						case 4:
							auxMenu='n';
							break;

						default:
							printf("\nIngrese opcion correcta\n\n");
							break;
					}
				}while (auxMenu=='s');
				customer_print(list,auxIndex);
				ret = 0;
			}
		}
		else
			{
				printf("\n/****Error - No se encuentran datos del Id ingresado****/\n");
			}
	}
	return ret;
}


// int customer_delete		 (Customer* listCust, int lenCust, Publication* listPub, int lenPub);

int customer_print(Customer* list, int index)
{
	int ret = -1;

	if(list != NULL && index >= 0)
	{
		if(list[index].isEmpty==FALSE)
		{
			printf("ID: %d - Nombre: %s - Apellido: %s - CUIT: %s",list[index].id, list[index].name, list[index].lastName, list[index].cuit);
			ret = 0;
		}
		else
		{
			printf("\n/****Error - No existe el cliente****/\n");
		}
	}
	return ret;
}

int customer_printArray(Customer* list , int len)
{
	int ret = -1;
	if (list != NULL && len >0){
		for (int i=0 ; i<len ; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("ID: %d - Nombre: %s - Apellido: %s - CUIT: %s\n",list[i].id, list[i].name, list[i].lastName, list[i].cuit);
			}
		}
		ret = 0;
	}
return ret;
}


int customer_freePosition(Customer* list, int len)
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

/** \brief find an Customer by Id and returns the index position in array.
 * \param list Customer*
 * \param len int
 * \param id int
 * \return Return Customer index position or (-1) if [Invalid length or NULL pointer received or Customer not found
 */
int customer_freePositionIndex(Customer* list, int len, int* pIndex)
{
	int ret = -1;
	int i;
		if (list != NULL && len >0 && pIndex != NULL)
        {
			for ( i = 0; i<len; i++)
			{
				if(list[i].isEmpty==TRUE)
				{
					*pIndex = i;
					ret = 0;
					break;
				}
			}
		}
	return ret;
}

int customer_searchId(Customer* list, int len, int id)
{
    int ret = -1;
    if (list!=NULL && len>0 && id>=0)
    {
        for (int i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE && list[i].id == id)
            {
				ret= i;
				break;
            }
        }
    }
    else
    {
        ret = 0;
    }
    return ret;
}
