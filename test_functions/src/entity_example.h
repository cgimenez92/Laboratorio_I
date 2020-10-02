/*
 * entity_example.h
 *
 *  Created on: 1 oct. 2020
 *      Author: cgimenez
 */

#ifndef ENTITY_EXAMPLE_H_
#define ENTITY_EXAMPLE_H_

#define TRUE 1
#define FALSE 0
#define STRING_SIZE 50
#define MIN_LIMIT 1
#define MAX_LIMIT 5
#define LENGHT_ARRAY_STRUCT 3
#define ASC 1
#define DSC 0

typedef struct
{
char name[STRING_SIZE];
int file;
int isEmpty;
int id;
} Entity;


    int entity_init(Entity * list, int len);
	int entity_create(Entity * list, int len);
	int entity_print(Entity * list , int len);
	int entity_delete(Entity * list, int len);
	int entity_update(Entity * list, int len, int index, int id);
	int entity_printIndex(Entity * list, int len, int index);
	int entity_freePosition(Entity * list, int len);
	int entity_freePositionIndex(Entity * list, int len, int * pIndex);
	int entity_searchIndex(Entity * list, int len, int id, int * pIndex);
#endif /* ENTITY_EXAMPLE_H_ */
