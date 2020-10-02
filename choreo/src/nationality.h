#ifndef NATIONALITY_H_
#define NATIONALITY_H_

#define TRUE 1
#define FALSE 0
#define LENGHT 50
#define MIN_LIMIT 1
#define MAX_LIMIT 5
#define LENGHT_ARRAY_STRUCT 3
typedef struct
{
char name[LENGHT];
int file;
int isEmpty;
int id;
} Nationality;


    int entity_init(Nationality * list, int len);
	int entity_create(Nationality * list, int len);
	int entity_print(Nationality * list , int len);
	int entity_delete(Nationality * list, int len);
	int entity_update(Nationality * list, int len, int index, int id);
	int entity_printIndex(Nationality * list, int len, int index);
	int entity_freePosition(Nationality * list, int len);
	int entity_freePositionIndex(Nationality * list, int len, int * pIndex);
	int entity_searchIndex(Nationality * list, int len, int id, int * pIndex);
#endif /* entity_H_ */
