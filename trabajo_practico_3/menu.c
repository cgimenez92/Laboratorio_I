/*
 * menu.c
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"

int menu()
{
	int option;
	getInt("\n1.  Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2.  Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
			"\n3.  Alta de empleado\n4.  Modificar datos de empleado\n5.  Baja de empleado\n6.  Listar empleados\n7.  Ordenar empleados"
			"\n8.  Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9.  Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\n"
			"\nIngrese opcion: ", "\n/****Error  - Ingresar opcion de 1-10****/\n", &option, 2, 1, 10);
	fflush(stdin);
    return option;
}

int menuValidationExit()
{
	int option;
	getInt("\nCUIDADO! Falta guardar en una o en ambas listas. Si sales ahora NO se guardaran los cambios.\nDesea salir de todos modos?\n1-Volver\n2-Salir\nIngrese una opcion: ",
			"\n/****Error - Ingresar opcion de 1-2****/\n",
			&option, 2, 1, 2);
	fflush(stdin);
    return option;
}
