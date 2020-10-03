/*
 * employee.c
 *
 *  Created on: 29 sep. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"
#include "employee.h"
#include "menu.h"

static int employee_newId (void);
static int employee_swapPostionInArray (Employee* list, int positionToSwap);

int employee_force_init(Employee* list, int len, char* name, char* lastName, float salary, int sector)
{
    int ret = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        i = employee_freePosition(list,len);
        if(i >= 0)
        {
        	strcpy(list[i].name,name);
			strcpy(list[i].lastName,lastName);
			list[i].salary = salary;
			list[i].sector = sector;
			list[i].isEmpty=FALSE;
			list[i].id = employee_newId();
        }
        ret = 0;
    }
    return ret;
}

static int employee_newId(void)
{
	static int id = 0;
	id = id+1;
	return id;
}

int employee_init(Employee * list, int len)
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

int employee_freePositionIndex(Employee * list, int len, int * pIndex)
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

int employee_print(Employee* list,int index)
{
	int ret = -1;

	if(list != NULL && index >= 0)
	{
		if(list[index].isEmpty==FALSE)
		{
			printf("ID: %d - Nombre: %s - Apellido: %s - Sueldo: %f - Sector: %d",list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);
			ret = 0;
		}else
		{
			printf("\n/****Error - No existe el usuario****/\n");
		}
	}
	return ret;
}

int employee_printArray(Employee * list , int len)
{
	int ret = -1;
	if (list != NULL && len >0){
		for (int i=0 ; i<len ; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("ID: %d - Nombre: %s - Apellido: %s - Sueldo: %f - Sector: %d\n",list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
			}
		}
		ret = 0;
	}
return ret;
}

int employee_create(Employee * list, int len)
{
int ret = -1;
int index;
Employee buffer;

	if (list != NULL && len >0)
	{
		if (!employee_freePositionIndex (list, len, &index))
		{
			if (
				!getName ("Ingrese nombre:", "Ingresar unicamente caracteres", buffer.name, 3, STRING_SIZE) &&
				!getName ("Ingrese Apellido:", "Ingresar unicamente caracteres", buffer.lastName, 3, STRING_SIZE) &&
				!getFloat("Ingrese Remuneracion:", "Ingresar unicamente numeros separados por (.) -> Ej: 100.00", &buffer.salary, 2, MIN_LIMIT_SALARY, MAX_LIMIT_SALARY) &&
				!getInt("Sector:", "Ingresar unicamente numeros", &buffer.sector, 2, MIN_LIMIT_SECTOR, MAX_LIMIT_SECTOR))
			{
					list[index] = buffer;
					list[index].id = employee_newId();
					list[index].isEmpty = FALSE;
			}
			else
				{
					printf("\n/****Error - Finalizaron la cantidad de intentos****/\n");
				}
		}
		else
			{
				printf("\n/****Error - No se encuentran espacios disponibles en el listado de empleados****/\n");
			}
	}
	return ret ;
}

int employee_update(Employee * list, int len)
{
	int ret = -1;
	int aux;
	int auxIndex;
	char auxMenu='s';
	Employee buffer;

	if(list != NULL && len > 0)
	{
		employee_printArray(list, len);
		if(!getInt("Ingrese el id del usuario que desea cambiar: ", "Ingresar unicamente numeros", &aux, 2, 1, 1000))
		{
			auxIndex=employee_searchId(list, len, aux);
			if(list[auxIndex].isEmpty==FALSE)
			{
				employee_print(list,auxIndex);
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
							if(!getFloat("Ingrese Remuneracion: ", "Ingresar unicamente numeros separados por (.) -> Ej: 100.00", &buffer.salary, 2, MIN_LIMIT_SALARY, MAX_LIMIT_SALARY) )
							{
								list[auxIndex].salary = buffer.salary;
							}
							break;
						case 4:
							if(!getInt("Sector: ", "Ingresar unicamente numeros", &buffer.sector, 2, MIN_LIMIT_SECTOR, MAX_LIMIT_SECTOR))
							{
								list[auxIndex].sector = buffer.sector;
							}
							break;
						case 5:
							auxMenu='n';
							break;

						default:
							printf("\nIngrese opcion correcta\n\n");
							break;
					}
				}while (auxMenu=='s');
				employee_print(list,auxIndex);
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

int employee_delete(Employee * list, int len)
{
	int ret = -1;
	Employee buffer;
	employee_printArray(list, len);

	if (list != NULL && len>0)
	{
		getInt("Ingrese id a borrar: ", "\n/****Error - No se encuentran datos del Id ingresado****/\n", &buffer.id, 2, MIN_LIMIT, MAX_LIMIT);
		for (int i=0 ; i<len ;  i++)
		{
			if (buffer.id == list[i].id)
			{
				list[i].isEmpty = TRUE;
				ret = 0;
			}
		}
	}
	return ret;
}

int employee_freePosition(Employee * list, int len)
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

int employee_searchId(Employee* list, int len, int id)
{
    int ret = -1;
    int i;
    if (list != NULL && len >0 && id >= 0)
    {
        for (i=0; i<len; i++)
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
        printf("Error\n");
    }
    return ret;
}

static int employee_swapPostionInArray (Employee* list, int positionToSwap)
{
	int ret = -1;
	Employee buffer;

	if(list != NULL && positionToSwap >= 0)
	{
		ret = 0;
		buffer = list[positionToSwap];
		list[positionToSwap] = list[positionToSwap+1];
		list[positionToSwap+1] = buffer;
	}

	return ret;
}

int employee_sortArray(Employee* list, int len, int order)
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
				if (order == 1 && (strnicmp(list[i].lastName, list[i+1].lastName, STRING_SIZE)>0 || //uno mayor que otro
								  (strnicmp(list[i].lastName, list[i+1].lastName, STRING_SIZE)==0 && list[i].sector > list[i+1].sector)))//iguales y otra variable para ordenar
				{
					employee_swapPostionInArray (list, i);
					flagSwap = 1;
				}
				else if(order == 0 && (strnicmp(list[i].lastName, list[i+1].lastName, STRING_SIZE)<0 || //uno menor que otro
									  (strnicmp(list[i].lastName, list[i+1].lastName, STRING_SIZE)==0 && list[i].sector < list[i+1].sector)))//iguales y otra variable para ordenar
					{
						employee_swapPostionInArray (list, i);
						flagSwap = 1;
					}
			}
		}while(flagSwap);
		ret = 0;
	}
	return ret;
}


int employee_avgSalary(Employee* list, int len, float* avgValue)
{
	int ret = -1;
	int buffer=0;
	int i=0;

	if(list != NULL && len > 0)
		{
			ret = 0;
			for (; i<len; i++)
			{
				buffer += list[i].salary;
			}
			*avgValue = buffer/len;
		}
	return ret;
}

int employee_sumSalary(Employee* list, int len, float* totalValue)
{
	int ret = -1;
	int buffer=0;
	int i=0;

	if(list != NULL && len > 0)
		{
			ret = 0;
			for (; i<len; i++)
			{
				buffer += list[i].salary;
			}
			*totalValue = buffer;
		}
	return ret;
}


