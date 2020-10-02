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
#define MAX_LIMIT 5
#define MIN_LIMIT_SALARY 1
#define MAX_LIMIT_SALARY 10000000
#define MIN_LIMIT_SALARY 1
#define MAX_LIMIT_SALARY 10000000
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

	int employee_force_init(Employee* list, int len, char* name, char* lastName, float salary, int sector);
    int employee_init(Employee * list, int len);
	int employee_create(Employee * list, int len);
	int employee_print(Employee* list,int index);
	int employee_printArray(Employee * list , int len);
	int employee_delete(Employee * list, int len);
	int employee_update(Employee * list, int len);
	int employee_printIndex(Employee * list, int len, int index);
	int employee_freePosition(Employee * list, int len);
	int employee_freePositionIndex(Employee * list, int len, int * pIndex);
	int employee_searchId(Employee* list, int len, int id);
	int employee_sortArray(Employee* list, int len, int order);

#endif /* EMPLOYEE_H_ */
