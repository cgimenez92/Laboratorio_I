/*
 * employee.h
 *
 *  Created on: 29 sep. 2020
 *      Author: cgimenez
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define TRUE 1
#define FALSE 0
#define STRING_SIZE 51
#define MIN_LIMIT 1
#define MAX_LIMIT 6
#define MIN_LIMIT_SALARY 1
#define MAX_LIMIT_SALARY 100000000
#define MIN_LIMIT_SECTOR 1
#define MAX_LIMIT_SECTOR 100
#define LENGHT_ARRAY_STRUCT 3
#define ASC 1
#define DSC 0

	typedef struct
	{
		int id;
		int isEmpty;
		char name[STRING_SIZE];
		char lastName[STRING_SIZE];
		float salary;
		int sector;
	} Employee;

	/** \brief add in a existing list of employees the values received as parameters
	 * in the first empty position
	 * \param list employee*
	 * \param len int
	 * \param name[] char
	 * \param lastName[] char
	 * \param salary float
	 * \param sector int
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
	free space] - (0) if Ok
	 */
	int employee_force_init(Employee* list, int len, char* name, char* lastName, float salary, int sector);

	/** \brief To indicate that all position in the array are empty,
	 * this function put the flag (isEmpty) in TRUE in all
	 * position of the array
	 * \param list Employee* Pointer to array of employees
	 * \param len int Array length
	 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	 */
    int employee_init(Employee * list, int len);

    /** \brief create a new employee in list
     * in the first empty position
     * \param list employee*
     * \param len int
     * \return int Return (-1) if Error [Invalid length or NULL pointer or without
    free space] - (0) if Ok
     */
	int employee_create(Employee * list, int len);

	/** \brief print the content of employees array
	 *
	 * \param list Employee*
	 * \param length int
	 * \return int
	 *
	 */
	int employee_print(Employee* list,int index);


	int employee_printArray(Employee * list , int len);

	/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
	 *
	 * \param list Employee*
	 * \param len int
	 * \param id int
	 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
	find a employee] - (0) if Ok
	 *
	 */
	int employee_delete(Employee * list, int len);
	int employee_update(Employee * list, int len);
	int employee_printIndex(Employee * list, int len, int index);
	int employee_freePosition(Employee * list, int len);
	int employee_freePositionIndex(Employee * list, int len, int * pIndex);

	/** \brief find an Employee by Id en returns the index position in array.
	 *
	 * \param list Employee*
	 * \param len int
	 * \param id int
	 * \return Return employee index position or (-1) if [Invalid length or NULL
	pointer received or employee not found]
	 *
	 */
	int employee_searchId(Employee* list, int len, int id);

	/** \brief Sort the elements in the array of employees, the argument order
	indicate UP or DOWN order
	 *
	 * \param list Employee*
	 * \param len int
	 * \param order int [1] indicate UP - [0] indicate DOWN
	 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	 *
	 */
	int employee_sortArray(Employee* list, int len, int order);

	int employee_avgSalary(Employee* list, int len, float* avgValue);
	int employee_sumSalary(Employee* list, int len, float* totalValue);

#endif /* EMPLOYEE_H_ */
