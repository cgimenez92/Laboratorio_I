/*
 ============================================================================
 Name        : choreo.c
 Author      : cgimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "nationality.h"

int main(void)
{
	int option;
	int index;
    int answerIndex;
	int idToSearch;

	Nationality arrayNationality[LENGHT_ARRAY_STRUCT];
	if (entity_init(arrayNationality, LENGHT_ARRAY_STRUCT) == 0)
    {
		do {
			 utn_getnumero(&option, "\n 1-Alta \n 2- Imprimir \n 3-Baja  \n  4-Modificar 5-Imprimir indice 6- buscarLibre 7- SALIR \n ", "Error\n",1,7,2);
			 switch (option){
			 case 1:
				entity_create(arrayNationality,LENGHT_ARRAY_STRUCT);
				 break;

			 case 2:
				entity_print(arrayNationality,LENGHT_ARRAY_STRUCT);
				 break;

			 case 3:
				 entity_delete(arrayNationality,LENGHT_ARRAY_STRUCT);
				 break;
			 case 4:
				utn_getnumero (&idToSearch, "Que ID Desea buscar","ERRROR",0,50,2);
				entity_searchIndex (arrayNationality,LENGHT_ARRAY_STRUCT,idToSearch,&index);
				printf("%d",index);
				entity_printIndex (arrayNationality,LENGHT_ARRAY_STRUCT, index);
				 break;
			 case 5:
				 utn_getnumero(&index, "Ingrese index", "Error\n",0,4,2);
				 entity_printIndex(arrayNationality,LENGHT_ARRAY_STRUCT,index);
				 break;
			 case 6:
				 answerIndex = entity_freePosition(arrayNationality, LENGHT_ARRAY_STRUCT);
				if (answerIndex != -1)
                {
					printf("El indice libre es: %d", answerIndex);
				} else {
					printf("No hay indices libres");
				}
				break;
			 }
		 }while (option != 7);
    }
	return EXIT_SUCCESS;
}
