#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//typedef struct TUPLE TUPLELIST;
//struct TUPLE{
//	int ID;
//	char Name[30];
//	char Address[50];
//	char Phone[10];
//	TUPLELIST next;
//};

struct CSG{
	char course[5]; //course name
	int SID; //student ID
	char grade[2]; //grade the student received
};

struct SNAP{ //student name address phone
	int studentID;
	char name[15];
	char address[20]; //address of the student
	int pNumber;	//phone number
};

struct CP{//course and its prerequisite
	char course[5];
	char prereq[5]; //prerequisite of the course
};

struct CDH{
	char course[5];
	char day[2];	//day of the week
	char time[4];	//time of the class
};

struct CR{
	char course[5];
	char room[15];
};

struct Database{
	struct LinkedList *list;
	int relations;
};
typedef struct Database DB;

void delete(char *c, DB *dataBase);
DB lookup(char *c, DB *dataBase);
void insert(char *c, DB *dataBase);
