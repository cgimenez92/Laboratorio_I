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


//
//
//void myFgets(char* buffer, int limit, FILE* archivo)
//{
//    int i=0;
//    fgets(buffer, limit, archivo);
//    buffer[limit-1] = '\0';
//    while(buffer[i] != '\0')
//    {
//        if(buffer[i] == 10)//10 -> LF
//        {
//            buffer[i] = '\0';
//            break;
//        }
//        i++;
//    }
//}
//
///////////////Valido Nombre/////////////////////////////
//
//int val_Name(char* buffer)
//{
//    int i=0;
//    int retorno = 0; // 0 esta bien
//
//    if ((buffer[i] < 97 || buffer[i] > 122) && (buffer[i] < 65 || buffer[i] > 90))
//    {
//        retorno = -1; // -1 esta mal
//    }
//
//    return retorno;
//}
//
//int val_GetName(char* vNombre, char* msg, char* msgError, int attempts, int limit) //
//{
//    int retorno = -1;
//    char buffer[BUFFER_MAXIMO_CHAR];
//
//    if(vNombre != NULL && limit > 0 && limit < BUFFER_MAXIMO_CHAR)
//    {
//        printf(msg);
//        myFgets(buffer, limit, stdin);
//
//        while(attempts>0)
//        {
//            if(val_Name(buffer) == -1)
//            {
//                printf(msgError);
//                myFgets(buffer, limit, stdin);
//                attempts--;
//            }
//            else
//            {
//                strncpy(vNombre, buffer, limit);
//                retorno = 0;
//                break;
//            }
//        }
//    }
//    return retorno;
//}
//
///////////////Valido Edad/////////////////////////////
//
//int val_Age (int* bAge)
//{
//    int retorno;
//    retorno = 0;
//
//    if(bAge<0 || bAge>150)
//    {
//        retorno = -1;
//    }
//    else
//    {
//        if(bAge == '.' || bAge == '-')
//        {
//            retorno = -1;
//        }
//    }
//
//    return retorno;
//}
//
//int getAge(int* age, char* msg, char* msgError, int attempts)
//{
//    int retorno = -1;
//    int bAge;
//
//    printf("%s",msg);
//    scanf("%d",&bAge);
//
//    for( ; attempts>0; attempts--)
//    {
//        if(val_Age(bAge) == -1)
//        {
//            printf("%s",msgError);
//            scanf("%d",&bAge);
//            continue;
//        }
//        else
//        {
//            *age = bAge;
//            retorno = 0;
//            break;
//        }
//    }
//    return retorno;
//}
//
///////////////Valido DNI/////////////////////////////
//
//int val_Dni(char* buffer)
//{
//    int i=0;
//    int retorno = 0;
//    int flagPunto = 0;
//
//    while(buffer[i] != '\0')
//    {
//
//        if(buffer[i] < '0' || buffer[i] > '9')
//        {
//            retorno = -1;
//            break;
//        }
//        else
//        {
//            if(buffer[i] == '-')
//            {
//                retorno = -2;
//                break;
//            }
//            else if(buffer[i] == '.')
//            {
//                flagPunto++;
//
//                if(flagPunto > 0)
//                {
//                    retorno = -3;
//                    break;
//                }
//            }
//        }
//        i++;
//    }
//    return retorno;
//}
//
//int val_getDni(char* vDni, char* msg, char* msgError, int attempts, int limit)
//{
//    int retorno = -1;
//    char buffer[BUFFER_MAXIMO_CHAR];
//
//    if(vDni != NULL && limit > 0 && limit < BUFFER_MAXIMO_CHAR)
//    {
//        printf(msg);
//
//        for( ; attempts>0; attempts--)
//        {
//            myFgets(buffer, limit, stdin);
//
//            if(val_Dni(buffer) < 0)
//            {
//                printf(msgError);
//                continue;
//            }
//            else
//            {
//                strncpy(vDni, buffer, limit);
//                retorno = 0;
//                break;
//            }
//        }
//    }
//    return retorno;
//}
//int esTelefono(char str[])
//{
//   int i=0;
//   int contadorGuiones=0;
//   while(str[i] != '\0')
//   {
//       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
//           return 0;
//       if(str[i] == '-')
//            contadorGuiones++;
//       i++;
//   }
//   if(contadorGuiones==1) // debe tener un guion
//        return 1;
//
//    return 0;
//}
