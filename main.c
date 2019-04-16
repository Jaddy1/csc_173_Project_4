#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"


struct Database{
	struct LinkedList *list;
	int relations
};
struct CSG{
	int ID;
	char Name[30];
	char Address[50];
	char Phone[10];
	TUPLELIST next;
};
//typedef TUPLELIST Course-Prerequisite[1009];

void delete(char * course, char * ID, char s, TUPLELIST t);
bool lookup(TUPLE a, TUPLELIST t);
void insert(TUPLE a, TUPLELIST t);

int main(void){
//	TUPLE randomStudents = ;
}


bool lookup(TUPLE a, TUPLELIST t){

	return false;
}

void delete(TUPLE a, TUPLELIST t){


}

void insert(TUPLE a, TUPLELIST t){

}
