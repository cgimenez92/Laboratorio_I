/*
 * entity_example.c
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"
#include "entity_example.h"

static int entity_newId (void);
static int entity_swapPostionInArray (Entity* list, Entity* buffer, int positionToSwap);

static int entity_newId(void)
{
	static int id = 0;
	id = id+1;
	return id;
}

int entity_init(Entity * list, int len)
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

int entity_freePositionIndex(Entity * list, int len, int * pIndex)
{
	int ret = -1;
	int i ;
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

int entity_print(Entity * list , int len)
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

int entity_create(Entity * list, int len)
{
int ret = -1;
int index;
Entity buffer;

	if (list != NULL && len >0)
	{
		if (!entity_freePositionIndex (list, len, &index))
		{
			if (!getInt("\nLegajo?", "\nError", &buffer.file, 2, MIN_LIMIT, MAX_LIMIT) &&
				!getName ("\n Ingrese nombre", "\nError", buffer.name, 3, STRING_SIZE))
			{
					list[index] = buffer;
					list[index].id = entity_newId();
					list[index].isEmpty = FALSE;
			}
			else
				{
					printf("Error");
				}
		}
		else
			{
				printf(" \n No quedan espacios libres");
			}
	}
	return ret ;
}

//int entity_read(Entity * list , int len)

int entity_update(Entity * list, int len, int index, int id)
{
	int retorno = -1;
	Entity buffer;

	if(list != NULL &&
		len > 0 &&
		index >=0 &&
		index < len &&
		list[index].isEmpty == FALSE)
	{
		if(!getInt("\nLegajo?", "\nError", &buffer.file, 2, MIN_LIMIT, MAX_LIMIT) &&
           !getName ("\nIngrese nombre", "\nError", buffer.name, 3, STRING_SIZE))
		{
			buffer.id = id;
			buffer.isEmpty = FALSE;
			list[index] = buffer;
			retorno = 0;
		}
	}
	else
	{
		printf("No se encuentran datos en indice\n");
	}
	return retorno;
}

int entity_delete(Entity * list, int len)
{
	int ret = -1;
	Entity buffer;

	if (list != NULL && len>0)
	{
		entity_print(list, len);
		getInt("\nIngrese legajo a borrar: ", "\nError", &buffer.file, 2, MIN_LIMIT, MAX_LIMIT);

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

int entity_freePosition(Entity * list, int len)
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

int entity_searchIndex(Entity* list, int len, int id, int* pIndex)
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

static int entity_swapPostionInArray (Entity* list, Entity* buffer, int positionToSwap)
{
	int ret = -1;

	if(list != NULL && buffer != NULL && positionToSwap >= 0)
	{
		ret = 0;
		buffer = list[positionToSwap];
		list[positionToSwap] = list[positionToSwap+1];
		list[positionToSwap+1] = buffer;
	}

	return ret;
}

int entity_sortArray(Entity* list, int len, int order) //Sort by two variables
{
	int ret = -1;
	int flagSwap;
	Entity buffer;

	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		do
		{
			flagSwap = 0;
			for(int i=0; i<(len-1); i++)
			{
				if (order == 0 && (strncmp(list[i].name, list[i+1].name, STRING_SIZE)>0 || //uno mayor que otro
								  (strncmp(list[i].name, list[i+1].name, STRING_SIZE)==0 && list[i].file > list[i+1].file)))//iguales y otra variable para ordenar
				{
					entity_swapPostionInArray (list, buffer, i);
				}
				else if(order == 1 && (strncmp(list[i].name, list[i+1].name, STRING_SIZE)<0 || //uno menor que otro
									  (strncmp(list[i].name, list[i+1].name, STRING_SIZE)==0 && list[i].file < list[i+1].file)))//iguales y otra variable para ordenar
					{
						entity_swapPostionInArray (list, buffer, i);
					}
			}
		}while(flagSwap);
		ret = 0;
	}
	return ret;
}
