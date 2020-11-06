#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#define SIZE_STRING 1024

/************************************************************************/
/********************************* LOAD *********************************/
/************************************************************************/

 /** \brief Carga los datos de los employees desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pToFile;
    char idAux[100];
    char nameAux[SIZE_STRING];
    char workedHoursAux[100];
    int i = -1;
    char salaryAux[100];
    Employee* employeeAux;
    if(pArrayListEmployee != NULL && path != NULL)
    {
        pToFile = fopen(path,"r");

        if(pToFile != NULL)
        {
            while(!feof(pToFile))
            {
                fscanf(pToFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nameAux, salaryAux,workedHoursAux);
                if(i != -1)
                {
                    employeeAux = employee_newParameters(idAux,nameAux,workedHoursAux,salaryAux);
                    if(employeeAux != NULL)
                    {
                        ll_add(pArrayListEmployee, employeeAux);
                    }
                    else
                    {
                        printf("\n ERROR EN EL ARCHIVO\n");
                        controller_deleteListEmployee(pArrayListEmployee);
                        i = 0;
                        break;
                    }
                }
                i++;
            }
            fclose(pToFile);
        }
        else
        {
            printf("No existe el archivo\n");
        }
    }
    return i;
}

/** \brief Carga los datos de los employees desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pToFile;
    Employee* employeeAux;
    int i = 0;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pToFile = fopen(path,"rb");
        if(pToFile != NULL)
        {
            while(!feof(pToFile))
            {
                employeeAux = (Employee*) malloc(sizeof(Employee));
                fread(employeeAux,sizeof(Employee), 1, pToFile);
                if(feof(pToFile))
                {
                    break;
                }
                if(employeeAux != NULL)
                {
                    ll_add(pArrayListEmployee, employeeAux);
                    i++;
                }
                else
                {
                    printf("\nERROR AL AÑADIR UN ELEMENTO A LA LISTA\n");
                }
            }
            fclose(pToFile);
        }
    }

    return i;
}

/** \brief Alta de employees
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    Employee* newEmployee;
    int idAux;
    if(pArrayListEmployee != NULL)
    {
        newEmployee = employee_new();
        controller_inputEmployeeName(newEmployee);
        controller_inputEmployeeSalary(newEmployee);
        controller_inputEmployeeWorkHours(newEmployee);
        idAux = controller_getNextID(pArrayListEmployee);
        employee_setId(newEmployee,idAux);

        if(ll_add(pArrayListEmployee,newEmployee))
        {
            printf("El empleado no se pudo agregar a la lista");
        }
        else
        {
            ret = 0;
        }
    }
    return ret;
}

/** \brief Modificar datos de employee
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int option;
    char name[STRING_SIZE];
    int workedHours;
    int salary;

    Employee* pEmployee;

    controller_ListEmployee(pArrayListEmployee);
    printf("\n--MENU DE EDICION DE EMPLEADOS--\n\nIngrese el id del empleado que desea modificar: ");
    scanf("%d",&id);

    pEmployee=PfindEmployeeById(id,pArrayListEmployee);
    if(pEmployee!=NULL)
    {

        printf("\nEDICION DE %s\n1)Nombre\n2)Horas de trabajo\n3)Sueldo\n4)Volver\nIngrese una opcion: ",pEmployee->name);
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Ingrese el nuevo nombre del empleado: ");
                fflush(stdin);
                gets(name);
                employee_setName(pEmployee,name);
                printf("\nNombre cambiado con exito!\n\n");
                break;
            case 2:
                printf("Ingrese las nuevas horas trabajadas del empleado: ");
                scanf("%d",&workedHours);
                employee_setWorkedHours(pEmployee,workedHours);
                printf("\nhoras trabajadas cambiadas con exito!\n\n");
                break;
            case 3:
                printf("Ingrese el nuevo sueldo del empleado: ");
                scanf("%d",&salary);
                employee_setSalary(pEmployee,salary);
                printf("\nSueldo cambiado con exito!\n\n");
                break;
            case 4:
                printf("\nVolviendo...n\n");
                break;
            default:
                printf("\nERROR. Opcion incorrecta!\n\n");
                break;
        }
    }
    return 1;
}

/** \brief Baja de employee
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int id;
    int validation;
    int index;

    printf("\n--MENU DE ELIMINACION DE EMPLEADO--\n\n");
    controller_ListEmployee(pArrayListEmployee);

    printf("Ingrese el id del empleado que desea eliminar: ");
    scanf("%d",&id);
    pEmployee=PfindEmployeeById(id,pArrayListEmployee);
    index=IfindEmployeeById(id,pArrayListEmployee);

    if(pEmployee!=NULL&&index!=-1)
    {
        printf("Esta seguro que quiere eliminar al empleado %s con id %d?\n1)Si\n2)No, volver\nIngrese una opcion: ",pEmployee->name,pEmployee->id);
        scanf("%d",&validation);
        while((validation!=1)&&(validation!=2))
        {
            printf("ERROR. Ingrese una opcion valida: ");
            scanf("%d",&validation);
        }
        if(validation==1)
        {
            employee_delete(pEmployee);
            ll_remove(pArrayListEmployee,index);
            printf("\nEmpleado eliminado con exito!\n\n");
        }
    }
    else
    {
        printf("\nNo se encontro el empleado con ese id.\n\n");
    }
    return 1;
}

/** \brief Listar employees
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    Employee* pEmployee;
    printf("\nID      |       NOMBRE       |   HORAS   |   SUELDO  |\n\n");
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        pEmployee=ll_get(pArrayListEmployee,i);
        printf("%d,%20s,%10d,%10d\n",pEmployee->id,pEmployee->name,pEmployee->workedHours,pEmployee->salary);
    }
    return 1;
}

/** \brief Ordenar employees
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;
    printf("\n--MENU ORDENAR LISTA--\n\n");
    printf("0)Descendente\n1)Ascendente\nIngrese una opcion: ");
    scanf("%d",&option);

    while(option!=0&&option!=1)
    {
        printf("ERROR. Ingrese opcion valida: ");
        scanf("%d",&option);
    }

    ll_sort(pArrayListEmployee,employee_sortByName,option);

    return 1;
}


/*---------------------------------------------------------------------*/
/*------------------------------- SAVES -------------------------------*/
/*---------------------------------------------------------------------*/


/** \brief Guarda los datos de los employees en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pToFile;
    Employee* employeeAux;
    int i;
    int listLen;
    int* idAux;
    char* nameAux;
    int* salaryAux;
    int* workedHoursAux;
    if(pArrayListEmployee != NULL && path != NULL)
    {
        idAux = malloc(sizeof(int));
        nameAux = malloc(sizeof(char)*SIZE_STRING);
        salaryAux = malloc(sizeof(int));
        workedHoursAux = malloc(sizeof(int));

        pToFile = fopen(path,"w");
        listLen = ll_len(pArrayListEmployee);
        fprintf(pToFile,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i<listLen; i++)
        {
            employeeAux = ll_get(pArrayListEmployee,i);
            employee_getId(employeeAux,idAux);
            employee_getSalary(employeeAux,salaryAux);
            nameAux = employee_getName(employeeAux);
            employee_getWorkedHours(employeeAux,workedHoursAux);
            fprintf(pToFile,"%d,%s,%d,%d\n",*idAux,nameAux,*salaryAux,*workedHoursAux);
        }
        free(nameAux);
        free(idAux);
        free(salaryAux);
        free(workedHoursAux);
        fclose(pToFile);
    }
    return ret;
}

/** \brief Guarda los datos de los employees en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pToFile;
    Employee* employeeAux;
    int i = 0;
    int listLen;
    if(pArrayListEmployee != NULL && path != NULL)
    {

        pToFile = fopen(path,"wb");
        listLen = ll_len(pArrayListEmployee);
        for(i=0; i< listLen; i++)
        {
            employeeAux = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(employeeAux, sizeof(Employee),1,pToFile);
        }
        fclose(pToFile);
    }
    return ret;
}


/*--------------------------------------------------------------------*/
/*-------------------------------INPUTS-------------------------------*/
/*--------------------------------------------------------------------*/

int controller_inputEmployeeName(Employee* employee)
{
    int ret = -1;
    char name[SIZE_STRING];
    int errorFlag = 0;
    int length;
    if(employee != NULL)
    {

        printf("Ingrese el nombre del empleado: ");
        do
        {

            if(errorFlag != 0)
            {

                printf("ERROR: Reingrese el nombre del empleado: ");
            }
            fflush(stdin);
            fgets(name,SIZE_STRING,stdin);
            length = strlen(name);
            if(name[length - 1] == '\n')
            {
                name[length - 1] = '\0';
            }
            errorFlag = employee_setName(employee, name);

        }
        while(errorFlag != 0);
        ret = 0;
    }
    return ret;
}


int controller_inputEmployeeSalary(Employee* employee)
{
    int ret = -1;
    int salary;
    int errorFlag = 0;
    if(employee != NULL)
    {

        printf("Ingrese el sueldo del empleado: ");
        do
        {
            if(errorFlag != 0)
            {
                printf("ERROR reingrese el sueldo del empleado: ");
            }
            fflush(stdin);
            if(scanf("%d", &salary))
            {
                errorFlag = employee_setSalary(employee, salary);
            }
            else
            {
                errorFlag = -1;
            }

        }
        while(errorFlag != 0);
    }
    return ret;
}

int controller_inputEmployeeWorkHours(Employee* employee)
{
    int ret = -1;
    int workedHours;
    int errorFlag = 0;
    if(employee != NULL)
    {

        printf("Ingrese las horas trabajadas por el empleado: ");
        do
        {
            if(errorFlag != 0)
            {
                printf("ERROR: reingrese las horas trabajadas por el empleado: ");
            }
            fflush(stdin);
            if(scanf("%d", &workedHours))
            {
                errorFlag = employee_setWorkedHours(employee, workedHours);
            }
            else
            {
                errorFlag = -1;
            }

        }
        while(errorFlag != 0);
    }
    return ret;
}

int controller_getNextID(LinkedList* pArrayListEmployee)
{
    int id = 0;
    int idAnterior;
    int auxiliar;
    Employee* employeeAux;
    int listLen;
    int i;

    if(pArrayListEmployee != NULL)
    {
        listLen = ll_len(pArrayListEmployee);
        if(listLen > 0)
        {
            for(i = 0; i<listLen; i++)
            {
                employeeAux = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(employeeAux,&auxiliar);
                if(auxiliar > id)
                {
                    idAnterior = id;
                    id = auxiliar;
                    if(idAnterior + 1 != id)
                    {
                        id = idAnterior;
                        break;
                    }
                }
            }
            id++;

        }
        else
        {
            id = 1;
        }

    }
    return id;
}

Employee* PfindEmployeeById(int id, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int i;

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        pEmployee=ll_get(pArrayListEmployee,i);
        if(pEmployee!=NULL)
        {
            if(pEmployee->id==id)
            {
                break;
            }
            else
            {
                pEmployee=NULL;
            }
        }
    }

    return pEmployee;
}


int controller_deleteListEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int len;
    int i;
    Employee* pEmployee;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            for(i=0; i<len; i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                employee_delete(pEmployee);
            }
            ll_deleteLinkedList(pArrayListEmployee);
            ret = 0;
        }
    }
    return ret;

}

int IfindEmployeeById(int id, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int index=-1;
    int i;

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        pEmployee=ll_get(pArrayListEmployee,i);
        if(pEmployee!=NULL)
        {
            if(pEmployee->id==id)
            {
                index=i;
                break;
            }
        }
    }

    return index;
}
