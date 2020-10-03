/*
 ============================================================================
 Name        : trabajo_practico_2.c
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
#include "employee.h"
#include "menu.h"
#define ARRAY_SIZE 1000
#define ASC 1
#define DSC 0

int main(void)
{
	setbuf(stdout, NULL);
	char seguir='s';
	int flag=0;
	float avg;
	float totalSalary;
	int i;
	Employee listEmployees[ARRAY_SIZE];
	employee_init(listEmployees, ARRAY_SIZE);
/*
 * BORRAR Para probar un listado de empleados
 *
	employee_force_init(listEmployees, ARRAY_SIZE, "Cristian", "Gimenez",123.15 ,1);
	employee_force_init(listEmployees, ARRAY_SIZE, "Tito", "Puente", 13245.2131 ,2);
	employee_force_init(listEmployees, ARRAY_SIZE, "Cristian", "Jimeno", 521.465 , 2);
	employee_force_init(listEmployees, ARRAY_SIZE, "Alberto", "Terrrero", 2345.54 , 5);
	employee_force_init(listEmployees, ARRAY_SIZE, "Homero", "Simpsons", 145.31, 4);

*/
	do
	{
		switch (menu())
		{
			case 1:
				employee_create(listEmployees, ARRAY_SIZE);
				flag++;
				break;
			case 2:
				if(flag>0)
				{
					if(!employee_update(listEmployees, ARRAY_SIZE))
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
					printf("\nNo se ingreso ningun empleado\n");
				}
				break;
			case 3:
				if(flag>0)
				{
					if(!employee_delete(listEmployees, ARRAY_SIZE))
					{
						printf("\nSe borro empleado correctamente");
					}
					else
					{
						printf("\nNo se pudo borrar empleado\n");
					}
				}
				else
				{
					printf("\nNo se ingreso ningun empleado\n");
				}

				break;
			case 4:
				if(flag>0)
				{
					if(!employee_sortArray(listEmployees, ARRAY_SIZE, ASC))
					{
						employee_printArray(listEmployees, ARRAY_SIZE);
						if(!employee_avgSalary(listEmployees, ARRAY_SIZE, &avg))
						{
							printf("\nA - El promedio de salarial es: %.2f\n",avg);

							for (i=0 ; i<ARRAY_SIZE && listEmployees[i].isEmpty == FALSE; i++)
							{
								if(listEmployees[i].salary > avg)
								{
									printf("\nB - Asalariados que superan el promedio: \nID: %d - Nombre: %s - Apellido: %s - Sueldo: %f - Sector: %d\n",listEmployees[i].id, listEmployees[i].name, listEmployees[i].lastName, listEmployees[i].salary, listEmployees[i].sector);
								}
							}
						}
						if(!employee_sumSalary(listEmployees, ARRAY_SIZE, &totalSalary))
						{
							printf("\nC - La suma total de la masa salarial es de:  %.2f\n",totalSalary);
						}
					}
				}
				else
				{
					printf("\nNo se ingreso ningun empleado\n");
				}
				break;
			case 5:
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

