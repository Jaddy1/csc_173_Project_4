#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "Databases.h"


struct Database{
	struct LinkedList *list;
	int relations;
};
typedef struct Database DB;

struct CSG{
	int ID;
	char Name[30];
	char Address[50];
	char Phone[10];
	DB next;
};
//typedef TUPLELIST Course-Prerequisite[1009];

void delete(char *c, DB *dataBase);
bool lookup(char *c, DB *dataBase);
void insert(char *c, DB *dataBase);

DB *newDatabase(int n){
	DB *db = (DB*)malloc(sizeof(DB));//allocating space in memory for the database
	db->list = new_LinkedList(); //using a linkedList to make a "table" for the information
	db->relations = n; //number of relations in the database
	return db;
}

int main(void){
//	TUPLE randomStudents = ;
}


bool lookup(char *c, DB *dataBase){

	return false;
}

void delete(char *c, DB *dataBase){


}

void insert(char *c, DB *dataBase){
	LinkedList *l = new_LinkedList();
	char *token; //initializes a token to be read from the string c
	char* copy = strdup(c); //creates a copy of string c to use for reading the original string c

	for(token = strtok(copy, ","); token != NULL; token = strtok(NULL, ",")){
		LinkedList_add_at_end(l, token); //adds a new "row" to the table with each value delimited by a comma as a column
	}
	LinkedList_add_at_end(dataBase->list, l);
}
