/*
 * employee.h
 *
 *  Created on: 3 nov. 2020
 *      Author: cgimenez
 */

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 128

typedef struct
{
    int id;
    char name[STRING_SIZE];
    int workedHours;
    int salary;
}Employee;

/** \brief Crea un nuevo objecto Employee
 *
 * \param void
 * \return  (NULL) si no hay memoria para crear el elemento.
 *          Employee* si TODO OK;
 *
 */
Employee* employee_new(void);

/** \brief Crea un nuevo empleado cargando los campos con informacion
 *
 * \param char* idStr string que contiene el ID
 * \param char* nameStr el name
 * \param char* salaryStr string que contiene el salary
 * \param char* horasStr string que contiene las Horas Trabajadas
 * \return (NULL): si los Parameters son nulos, los Parameters son incorrectos o no hay espacio disponible
 *         Employee*: TODO OK
 */
 // nota Se usaron char* por respetar la funcion recibida.
Employee* employee_newParameters(char*,char*,char*, char*);

/** \brief Elimina un empleado de memoria
 *
 * \param this Employee* el empleado a eliminar
 * \return void
 */
void employee_delete(Employee* this);

/** \brief establece el id de un empleado
 * \param this Employee* empleado a modificar
 * \param id int nuevo Id
 * \return int  (-1) ERROR: employee* es NULL o Id incorrecto.
 *               (0) TODO BIEN
 */

int employee_setId(Employee* this,int id);

/** \brief se obtiene valor de id de un empleado
 * \param this Employee* Empleado objectivo
 * \param id int* dirrecion donde se copia el valor del Id
 * \return int (-1) ERROR: si los Parameters son NULL
 *              (0) TODO BIEN.
 */
int employee_getId(Employee* this,int* id);

/** \brief establece el name del empleado
 * \param this Employee* empleado a modificar
 * \param name char* nuevo name
 * \return int (-1) ERROR: employee* es NULL o name incorrecto.
 *               (0) TODO BIEN
 */
int employee_setName(Employee* this,char* name);

/** \brief se obtiene el name del empleado
 *
 * \param this Employee* Empleado Objectivo
 * \return char* (NULL) ERROR: parametro es NULL
 *               char* TODO BIEN
 *
 */
char* employee_getName(Employee* this);

/** \brief establece la carga horaria de un empleado
 *
 * \param this Employee* empleado a modificar
 * \param id int la nueva carga horaria
 * \return int  (-1) ERROR: employee* es NULL o horas trabajadas incorrecta.
 *               (0) TODO BIEN
 *
 */
int employee_setWorkedHours(Employee* this,int workedHours);
/** \brief se obtiene valor de la carga horaria de un empleado
 *
 * \param this Employee* Empleado objectivo
 * \param id int* dirrecion donde se copia el valor de las horas trabajadas
 * \return int (-1) ERROR: si los Parameters son NULL
 *              (0) TODO BIEN.
 *
 */
int employee_getWorkedHours(Employee* this,int* workedHours);

/** \brief establece el salary de un empleado
 *
 * \param this Employee* empleado a modificar
 * \param id int nuevo salary
 * \return int  (-1) ERROR: employee* es NULL o salary incorrecto.
 *               (0) TODO BIEN
 *
 */
int employee_setSalary(Employee* this,int salary);
/** \brief se obtiene valor del salary de un empleado
 *
 * \param this Employee* Empleado objectivo
 * \param id int* dirrecion donde se copia el valor del salary
 * \return int (-1) ERROR: si los Parameters son NULL
 *              (0) TODO BIEN.
 *
 */
int employee_getSalary(Employee* this,int* salary);

/** \brief Muestra la informacion de un empleado
 *
 * \param this Employee* empleado a mostrar
 * \return int (-1) ERROR: parametro Employee* NULL
 *              (0) TODO BIEN
 *
 */
int employee_print(Employee* this);


/** \brief define entre 2 employe quien tiene el mayor salary.
 *
 * \param cajaA void* Se espra que el dato sea un employee*
 * \param cajaB void* Se espra que el dato sea un employee*
 * \return int:
 *             (0) si: los elementos son iguales o ERROR: Parameters NULL o los elementos no son employee
 *             (1) si: A tiene un salrio mas grande que B
 *             (-1) si: B tiene un salrio mas grande que A
 */
int employee_orderBySalary(void* cajaA,void* cajaB);

/** \brief define entre 2 employee quien trabaja mas.
 *
 * \param cajaA void* Se espra que el dato sea un employee*
 * \param cajaB void* Se espra que el dato sea un employee*
 * \return int:
 *             (0) si: los elementos son iguales o ERROR: Parameters NULL o los elementos no son employee
 *             (1) si: A trabaja mas  que B
 *             (-1) si: B trabaja mas  que A
 */
int employee_sortByHour(void* cajaA,void* cajaB);

/** \brief define entre 2 employee quien tiene el orden alfabetico menor.
 *
 * \param cajaA void* Se espra que el dato sea un employee*
 * \param cajaB void* Se espra que el dato sea un employee*
 * \return int (-2) si: ERROR: Los Parameters Son NULL o No son tipo Employee.
 *             (0) si: los elementos son iguales
 *             (1) si: A tiene mayor valor ASCII que B
 *             (-1) si: B tiene mayor valor ASCII que A
 */
int employee_sortByName(void* cajaA,void* cajaB);

#endif // employee_H_INCLUDED
