/*
 * nationality.c
 *
 *  Created on: 29 sep. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "nationality.h"

static int entity_newID (void);

static int entity_newID(void)
{
	static int id = 0;
	id = id+1;
	return id;
}


int entity_init(Nationality * list, int len)
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

int entity_create(Nationality * list, int len)
{
int ret = -1;
int index;

Nationality bufferNationality;
	if (list != NULL && len >0)
	{
		if (entity_freePositionIndex (list, len, &index) == 0)
		{
				if (utn_getnumero(&bufferNationality.file, "\n Legajo?", "error",  MIN_LIMIT, MAX_LIMIT,2) == 0 &&
					utn_getNombre(bufferNationality.name, LENGHT, " \n Ingrese nombre","ERROR",3) == 0)
				{
						list[index] = bufferNationality;
						list[index].id = entity_newID();
						list[index].isEmpty = FALSE;
				} else
					{
						printf("Error");
					}
			} else
			{
				printf(" \n No quedan espacios libres");
			}
		}
	return ret ;
}


int entity_print(Nationality * list , int len)
{
	int ret = -1;
	if (list != NULL && len >0){
		for (int i=0 ; i<len ; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - file: %d - ID %d",list[i].name, list[i].file, list[i].id);
			}
		}
		ret = 0;
	}
return ret;
}


int entity_delete(Nationality * list, int len)
{
	int ret = -1;
	int buffer;
			if (list != NULL && len>0){
				entity_print(list, len);
			utn_getnumero(&buffer,"Ingrese file a borrar","Error", MIN_LIMIT, MAX_LIMIT,3);
			for (int i = 0 ; i<len ;  i++)
            {
				if (buffer == list[i].file)
                {
					list[i].isEmpty = TRUE;
				}
			}
		}
	return ret;
}

int entity_update(Nationality * list, int len, int index, int id)
{
	int retorno = -1;
	Nationality bufferNationality;

	if(list != NULL &&
		len > 0 &&
		index >=0 &&
		index < len &&
		list[index].isEmpty == FALSE)
	{
		if(utn_getnumero("\nLegajo:","\nError",&bufferNationality.file,2,MAX_LIMIT,MIN_LIMIT) == 0 &&
		   utn_getString("\nNombre:","\nError",bufferNationality.name,2,LENGHT) == 0)
		{
			bufferNationality.id = id;
			bufferNationality.isEmpty = FALSE;
			list[index] = bufferNationality;
			retorno = 0;
		}
	}
	else
	{
		printf("No se encuentran datos en indice\n");
	}
	return retorno;
}

int entity_freePosition(Nationality * list, int len)
{
	int ret = -1;
	int i ;
		if (list != NULL && len >0)
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

int entity_freePositionIndex(Nationality * list, int len, int * pIndex)
{
	int ret = -1;
	int i ;
		if (list != NULL && len >0 && pIndex != NULL)
        {
			for ( i = 0; i<len; i++) {
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

int entity_searchIndex(Nationality* list, int len, int id, int* pIndex)
{
    int ret = -1;
    int i;
    if (list != NULL && len >0 && pIndex != NULL && id >= 0)
    {
        for ( i = 0; i<len; i++)
        {
            if(list[i].id == id)
            {
            *pIndex = i;
            ret = 0;
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

