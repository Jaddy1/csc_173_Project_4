#ifndef RELATIONS_H
#define RELATIONS_H

#include "Database.h"
#include "LinkedList.h"

typedef struct CSG{
	char course[5]; //course name
	int SID; //student ID
	char grade[2]; //grade the student received
}CSG_Relation;

typedef struct SNAP{ //student name address phone
	int studentID;
	char name[15];
	char address[20]; //address of the student
	int pNumber;	//phone number
}SNAP_Relation;

typedef struct CP{//course and its prerequisite
	char course[5];
	char prereq[5]; //prerequisite of the course
}CP_Relation;

typedef struct CDH{
	char course[5];
	char day[2];	//day of the week
	char time[4];	//time of the class
}CDH_Relation;

typedef struct CR{
	char course[5];
	char room[15];
}CR_Relation;


CSG_Relation* new_CSG(char *C, int S, char *G);
void insert_CSG(DB *db, CSG_Relation *csg);
void insert_SNAP(DB *db, SNAP_Relation *snap);
void insert_CP(DB *db, CP_Relation *cp);
void insert_CDH(DB *db, CDH_Relation *cdh);
void insert_CR(DB *db, CR_Relation *cr);
void delete_CSG(DB *db, char *C, char *S, char *G);
void delete_SNAP(DB *db, char *S, char *N, char *A, char *P);
void delete_CP(DB *db, char *C, char *P);
void delete_CDH(DB *db, char *C, char *D, char *H);
void delete_CR(DB *db, char *C, char *R);
void lookup_CSG(DB *db, char *C, char *S, char *G);
void lookup_SNAP(DB *db, char *S, char *N, char *A, char *P);
void lookup_CP(DB *db, char *C, char *P);
void lookup_CDH(DB *db, char *C, char *D, char *H);
void lookup_CR(DB *db, char *C, char *P);


#endif