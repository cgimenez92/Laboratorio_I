/*
 * is_valid.c
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */
#include <stdio.h>
#include <stdlib.h>

//static int isValidNameEmail(char*cadena, int limite);
//static int isValidDomain(char*cadena, int limite);
//static int isValidDotCom(char*cadena, int limite);
//static int isValidRefLocationEmail(char*cadena, int limite);


int isValidInt(char*string)
{
	int ret = 1;
	int i = 0;

	for (i = 0 ; string[i] != '\0'; i++)
	{
		if (string[i] > '9' || string[i] < '0')
		{
			ret = 0;
			break;
		}
	}
	return ret;
}

/*
 * esFlotante: Verifica si la cadena ingresada es flotante
 * cadena: cadena de caracteres a ser analizada
 * limite: limite de la cadena
 * Retorno: 1 (verdadero) si la cadena es flotante , 0 (falso) si no y -1 en caso de ERROR de parametro
 *
 */
int isValidFloat(char*string, int limit)
{
	int ret = -1;
	int i = 0;
	int countPoints = 0;

	if(string != NULL && limit > 0)
	{
		ret = 1;
		if(string[0] != '+' || string[0] != '-')
		{
			i = 1;
		}
		while(string[i] != '\0')
		{
			if((string[i] < '0' || string[i] > '9') && string[i] != '.')
			{
				ret = 0;
				break;
			}
			if(string[i] == '.')
			{
				countPoints++;
				if(countPoints > 1)
				{
					ret = 0;
					break;
				}
			}
			i++;
		}
	}
	return ret;
}


int isValidName(char*string, int limit)
{
	int ret = 1;
	int i;

	for (i = 0 ; i<=limit && string[i] != '\0'; i++)
	{
		if	((string[i] < 'a' || string[i] > 'z') &&
			 (string[i] < 'A' || string[i] > 'Z') &&
			  string[i] != '.')
		{
			ret = 0;
			break;
		}
	}
	return ret;
}

//
//int isValidEmail(char*cadena, int limite)
//{
//	int ret=0;
//
//	for (int i=0;i<limite && cadena[i] != '\0';i++)
//	{
//		if(isValidNameEmail(cadena, 64))
//		{
//			if(cadena[i] == '@' && isValidDomain(cadena, 255))
//			{
//				if(cadena[i] == '.' && isValidDotCom(cadena, 3))
//				{
//					if(cadena[i] == '.' && isValidRefLocationEmail(cadena, 2))
//					{
//						ret = 1;
//						break;
//					}
//					else
//					{
//						ret =-4;
//						break;
//					}
//				}
//				else
//				{
//					ret =-3;
//					break;
//				}
//			}
//			else
//			{
//				ret =-2;
//				break;
//			}
//		}
//		else
//		{
//			ret =-1;
//			break;
//		}
//	}
//	return ret;
//}
//
//static int isValidNameEmail(char*cadena, int limite)
//{
//	int retorno = 1;
//	int i;
//
//	for (i=0; i<=limite && cadena[i] != '@'; i++)
//	{
//		if	((cadena[i] < 'a' || cadena[i] > 'z') &&
//			 (cadena[i] < 'A' || cadena[i] > 'Z'))
//		{
//			retorno = 0;
//			break;
//		}
//	}
//	return retorno;
//}
//
//static int isValidDomain(char*cadena, int limite)
//{
//	int retorno = 1;
//	int i ;
//
//	for (i = 0 ; i<=limite && cadena[i] != '.'; i++)
//	{
//		if	((cadena[i] < 'a' || cadena[i] > 'z') &&
//			 (cadena[i] < 'A' || cadena[i] > 'Z') &&
//			 (cadena[i] > '9' || cadena[i] < '0') &&
//			 cadena[i]!= '-' && cadena[i] != '.')
//		{
//			retorno = 0;
//			break;
//		}
//	}
//	return retorno;
//}
//
//static int isValidDotCom(char*cadena, int limite)
//{
//	int retorno = 1;
//	int i ;
//
//	for (i = 0 ; i<=limite && cadena[i] != '.'; i++)
//	{
//		if	((cadena[i] < 'a' || cadena[i] > 'z') &&
//			 (cadena[i] < 'A' || cadena[i] > 'Z') &&
//			 cadena[i] != '.')
//		{
//			retorno = 0;
//			break;
//		}
//	}
//	return retorno;
//}
//
//static int isValidRefLocationEmail(char*cadena, int limite)
//{
//	int retorno = 1;
//	int i ;
//
//	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++)
//	{
//		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
//		{
//			retorno = 0;
//			break;
//		}
//	}
//	return retorno;
//}
//
//int isValidPhone(char*cadena, int limite)
////
////{
////	int retorno = 1;
////	int i ;
////
////	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++)
////	{
////		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
////		{
////			retorno = 0;
////			break;
////		}
////	}
////	return retorno;
////}
//
//int isValidCellPhone(char*cadena, int limite)
////
////{
////	int retorno = 1;
////	int i ;
////
////	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++)
////	{
////		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
////		{
////			retorno = 0;
////			break;
////		}
////	}
////	return retorno;
////}
//
//int isValidPassword(char*cadena, int minLimit, int maxLimit)
////
////{
////	int retorno = 1;
////	int i ;
////
////	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++)
////	{
////		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
////		{
////			retorno = 0;
////			break;
////		}
////	}
////	return retorno;
////}
//
//int isValidURL(char*cadena, int limite)
////
////{
////	int retorno = 1;
////	int i ;
////
////	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++)
////	{
////		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
////		{
////			retorno = 0;
////			break;
////		}
////	}
////	return retorno;
////}
//
//int isValidMacAdress(char*cadena, int limite)
////
////{
////	int retorno = 1;
////	int i ;
////
////	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++)
////	{
////		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
////		{
////			retorno = 0;
////			break;
////		}
////	}
////	return retorno;
////}
//
//int isValidSerialNumber(char*cadena, int limite)
////
////{
////	int retorno = 1;
////	int i ;
////
////	for (i = 0 ; i<=limite && cadena[i] != '\0'; i++)
////	{
////		if	((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
////		{
////			retorno = 0;
////			break;
////		}
////	}
////	return retorno;
////}
