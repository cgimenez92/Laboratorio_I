#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* la direccion del archivo
 * \param pArrayListEmployee LinkedList* la lista donde se cargan los datos
 * \return int (-1) ERROR: parametros NULOS, archivo inexistente, O se ecuentra un elemento que no es employee
 *              (N) : devolvera la cantidad de empleados(N) cargados.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* la direccion del archivo
 * \param pArrayListEmployee LinkedList* la lista donde se cargan los datos
 * \return int (-1) ERROR: parametros NULOS, archivo inexistente o se ecuentra un elemento que no es employee
 *              (N) : devolvera la cantidad de empleados(N) cargados.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* la lista donde se guardara el empleado
 * \return int (-1) ERROR si: se recibe un puntero a NULL
 *               0 si: todo OK;
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado, Buscar empleado a modificar
 *
 * \param pArrayListEmployee LinkedList* la lista donde esta guardado el empleado
 * \return int (-1) ERROR si: se recibe un puntero a NULL o La lista recibida no tiene elementos.
 *              (0) si el usuario cierra la busqueda( TODO OK ).
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado, Buscar empleado a Eliminar
 *
 * \param pArrayListEmployee LinkedList* la lista donde esta guardado el empleado
 * \return int (-1) ERROR si: se recibe un puntero a NULL o La lista recibida no tiene elementos.
 *              (0) si el usuario cierra la busqueda( TODO OK ).
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* la lista donde estan guardados los empleados
 * \return int (-1) ERROR si: se recibe un puntero a NULL o La lista recibida no tiene elementos.
 *              (0) si el usuario cierra la busqueda( TODO OK ).
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados, muestra la lista ordenada
 *
 * \param pArrayListEmployee LinkedList* la lista donde estan guardados los empleados
 * \return int (-1) ERROR si: se recibe un puntero a NULL o La lista recibida no tiene elementos.
 *              (0) si el usuario cierra la busqueda( TODO OK ).
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* la direccion del archivo
 * \param pArrayListEmployee LinkedList* la lista donde se guardan los datos
 * \return int (-1) ERROR si: se le pasa un puntero a NULL
 *              (0) si: TODO OK
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* la direccion del archivo
 * \param pArrayListEmployee LinkedList* la lista donde se guardan los datos
 * \return int (-1) ERROR si: se le pasa un puntero a NULL.
 *              (0) si: TODO OK
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Crea el siguiente Id para la lista de empleados.
 *
 * \param pArrayListEmployee LinkedList* lista de empleados.
 * \return int (-1) ERROR si: se le pasa una lista NULA
 *              N si: el ID generado
 *
 */
int controller_getNextID(LinkedList* pArrayListEmployee);

/** \brief Busca un Empleado por su ID
 *
 * \param pArrayListEmployee LinkedList* Lista donde esta el empleado
 * \return Employee* (NULL) ERROR si: la lista pasada es Nula o El id ingresado no esta en la lista.
 *                   Empleadoy* si: se encontro el empleado a buscado.
 *
 */
Employee* PfindEmployeeById(int id, LinkedList* pArrayListEmployee);

/** \brief Pide al usuario un nombre para un empleado
 *
 * \param Employee* empleado a nombrar
 * \return int (-1) si el empleado es NULL
 *              (0) si la cargar del nombre fue sactifactoria TODO OK
 *
 */
int controller_inputEmployeeName(Employee*);
/** \brief Pide al usuario el sueldo para un empleado
 *
 * \param Employee* empleado a modificar
 * \return int (-1) si el empleado es NULL
 *              (0) si la cargar del sueldo fue sactifactoria TODO OK
 *
 */
int controller_inputEmployeeSalary(Employee*);
/** \brief Pide al usuario las horas trabajadas para un empleado
 *
 * \param Employee* empleado a modificar
 * \return int (-1) si el empleado es NULL
 *              (0) si la cargar de la carga horaria fue sactifactoria TODO OK
 *
 */
int controller_inputEmployeeWorkHours(Employee*);



/** \brief Funcion para Eliminar Empleado(con Confirmacion)
 *
 * \param pArrayListEmployee LinkedList* lista donde esta guardado el empleado
 * \param target Employee* el empleado a eliminar
 * \return int  (-1) SI: ERROR:Parametros Nulos, ERROR:No se encontro el empleado en la lista, TODO OK: se cancelo la operacion
 *              (0) SI: TODO OK:El empleado fue elimado.
 *
 */
int controller_deleteEmployee(LinkedList* pArrayListEmployee, Employee* target);

/** \brief Borra Una lista Y todos sus elementos de la memoria.
 *
 * \param pArrayListEmployee LinkedList* lista a borrar
 * \return int (-1) ERROR: Lista Nula.
 *              (0) TODO OK: Lista borrada.
 *
 */
int controller_deleteListEmployee(LinkedList* pArrayListEmployee);


int IfindEmployeeById(int id, LinkedList* pArrayListEmployee);

#endif /* CONTROLLER_H_ */
