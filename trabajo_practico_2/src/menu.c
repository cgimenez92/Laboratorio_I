/*
 * menu.c
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "gets.h"

int menu()
{
	int option;
	getInt("\n1-Alta empleado\n2-Modificar empleado\n3-Baja empleado\n4-Informes\n5-Salir\n\nIngrese opcion: ", "\nError - Ingresar opcion de 1-5", &option, 2, 1, 5);
	fflush(stdin);
    return option;
}

int menuChangeParameter()
{
	int option;
	system("cls");
	getInt("\n1-Modificar nombre\n2-Modificar apellido\n3-Modificar salario\n4-Modificar sector\n5-Salir\n\nIngrese opcion: ", "\nError - Ingresar opcion de 1-5", &option, 2, 1, 5);
	fflush(stdin);
    /*Nombre; apellido, salario; sector*/
    /*Listados por apellido y sector*/
    /*Total y prmedio de salarios*/
    /*Q empleados superan el salario promedio*/
    return option;
}
