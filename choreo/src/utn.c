#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "nationality.h"

static int myGets (char* cadena, int longitud);
static int getInt (int* pResultado);
static int getFlt (float* pResultado);
static int esNumerica (char* cadena);
static int esNombre (char*cadena, int limite);


static int myGets (char* cadena, int longitud){
		fflush (stdin);
		fgets(cadena,longitud,stdin);
		cadena[strnlen(cadena,sizeof(cadena))-1]='\0';
		return 1;
}

static int getInt (int* pResultado){
	int retorno = -1 ;
	char buffer[4096];
	if (myGets(buffer,sizeof(buffer)) == 1  && esNumerica(buffer)== 1){
		retorno = 0;
		*pResultado = atoi(buffer);
	}
	return retorno;
}
static int getFlt (float* pResultado){
	int retorno = -1 ;
	char buffer[4096];
	if (myGets(buffer,sizeof(buffer)) == 1  && esNumerica(buffer)== 1){
		retorno = 0;
		*pResultado = atof(buffer);
	}
	return retorno;
}

static int esNumerica(char*cadena){
	int retorno = 1 ;
	int i = 0;
	for (;cadena[i] != '\0';i++) {
		if (cadena[i] > '9' || cadena[i] < '0')
		{
				retorno = 0;
				break;
			}
	}
	return retorno;
}


int utn_getnumero (int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int intentos){

	int retorno = -1;
	int bufferInt;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
	do {
		printf("%s\n", mensaje);
		fflush(stdin);
		if (getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
		*pResultado = bufferInt;
		retorno = 0;
		break;
		}
		else
		{
		printf("%s \n", mensajeError);
		intentos--;
		}
	} while (intentos >= 0 );

	}
	return retorno;
}

int utn_getFloat (float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int intentos){

	int retorno = -1;
	float bufferFloat;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo>minimo && intentos>=0) {
	do {
		printf("%s\n", mensaje);
		fflush(stdin);
		if (getFlt(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
		{
		*pResultado = bufferFloat;
		retorno = 0;
		break;
		}
		else
		{
		printf("%s \n", mensajeError);
		intentos--;
		}
	} while (intentos >= 0 );

	}
	return retorno;
}


int utn_getNombre (char * pResultado, int len, char *mensaje, char* mensajeError, int intentos){
	int retorno = -1 ;
	char buffer[4096];
	if (pResultado != NULL && len>0 && mensaje != NULL && mensajeError != NULL  && intentos>=0) {
		do {
			printf("%s\n", mensaje);
			fflush(stdin);
			if ( myGets(buffer,sizeof(buffer)) && esNombre(buffer,len) )
			{
				retorno = 0;
				strncpy(pResultado,buffer,len);
				break;
			}
			else
			{
			printf("%s \n", mensajeError);
			intentos--;
			}
		} while (intentos >= 0 );

		}



	return retorno;
}

static int esNombre (char*cadena, int limite) {
	int retorno = 1;
	int i ;
	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++){
		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
		{
			retorno = 0;
			break;
		}}
	return retorno;
}
