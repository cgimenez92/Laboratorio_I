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
	getInt("\n1-Alta cliente\n2-Modificar datos del cliente\n3-Baja de cliente\n4-Publicar\n5-Pausar publicacion\n6-Reanudar publicacion\n7-Imprimir Clientes\n8-Informar\n9-Salir\n\nIngrese opcion: ", "\n/****Error  - Ingresar opcion de 1-9****/\n", &option, 2, 1, 9);
	fflush(stdin);
    return option;
}

int menuChangeParameter()
{
	int option;
	getInt("\n1-Modificar nombre\n2-Modificar apellido\n3-Modificar CUIT\n4-Salir\n\nIngrese opcion: ", "\n/****Error - Ingresar opcion de 1-4****/\n", &option, 2, 1, 4);
	fflush(stdin);
    return option;
}

int menuReports()
{
	int option;
	getInt("\n1-Cliente con mas avisos\n2-Cantidad de avisas pausados\n3-Rubro con mas avisos\n4-Salir\n\nIngrese opcion: ", "\n/****Error - Ingresar opcion de 1-4****/\n", &option, 2, 1, 4);
	fflush(stdin);
    return option;
}
