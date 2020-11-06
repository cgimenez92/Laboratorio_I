/*
 ============================================================================
 Name        : trabajo_practico_3.c
 Author      : cgimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include "gets.h"

int main()
{
	setbuf(stdout, NULL);
    int addElements = 0;
    int option;
    int flagLoad = 0;
    int saveText = 0;
    int saveBinary = 0;
    int validationExit;
    LinkedList* employeeList = ll_newLinkedList();

    do
    {
    	option = menu();
        switch(option)
        {

        case 1:
            if(addElements < 1)
            {
                addElements = controller_loadFromText("data.csv", employeeList);
                if(addElements != -1)
                {
                    printf("Se cargaron %d Empleados\n", addElements);
                    flagLoad=1;
                }
                else
                {
                    printf("Error Al cargar la lista\n");
                }
            }
            else
            {
                printf("Esta lista ya fue cargada...\n");
            }
            break;
        case 2:
            if(addElements < 1)
            {
                addElements = controller_loadFromBinary("data.dat", employeeList);
                printf("Se cargaron %d Empleados\n", addElements);
                flagLoad=1;
            }
            else
            {
                printf("Esta lista ya fue cargada...\n");
            }
            break;
        case 3:
            if(flagLoad)
            {
                controller_addEmployee(employeeList);
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;
        case 4:
            if(flagLoad)
            {
                controller_editEmployee(employeeList);
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;

        case 5:
            if(flagLoad)
            {
                controller_removeEmployee(employeeList);
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;
        case 6:
            if(flagLoad)
            {
                controller_ListEmployee(employeeList);
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;
        case 7:
            if(flagLoad)
            {
                controller_sortEmployee(employeeList);
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;
        case 8:
            if(flagLoad)
            {
                controller_saveAsText("data.csv",employeeList);
                printf("\nGuardado en lista de TEXTO exitosamente!\n\n");
                saveText=1;
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");

            }
            break;
        case 9:
            if(flagLoad)
            {
                controller_saveAsBinary("data.bin",employeeList);
                printf("\nGuardado en lista BINARIA exitosamente!\n\n");
                saveBinary=1;
            }
            else
            {
                printf("\nPrimero debe cargar la lista al sistema!\n\n");
            }
            break;
        case 10:
            if(saveText !=1 || saveBinary !=1)
            {
                validationExit = menuValidationExit();
                if(validationExit!=2)
                {
                    printf("\nVolviendo...\n\n");
                    option = menu();
                    continue;
                }
                else
                {
                    exit(0);
                }
            }
            else
            {
                printf("\nHasta luego!\n");
                exit(0);
            }
            break;

        default:
            printf("No ingreso una opcion Valida\n");
            break;
        }
    }
    while(option != 10);

    controller_deleteListEmployee(employeeList);
    return EXIT_SUCCESS;
}
