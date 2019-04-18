#ifndef RELATIONS_H
#define RELATIONS_H

#include "Database.h"
#include "LinkedList.h"

typedef struct CSG{
	char *course; //course name
	char *SID; //student ID
	char *grade; //grade the student received
}CSG_Relation;

typedef struct SNAP{ //student name address phone
	char *SID;
	char *name;
	char *address; //address of the student
	char *pNumber;	//phone number
}SNAP_Relation;

typedef struct CP{//course and its prerequisite
	char *course;
	char *prereq; //prerequisite of the course
}CP_Relation;

typedef struct CDH{
	char *course;
	char *day;	//day of the week
	char *hour;	//time of the class
}CDH_Relation;

typedef struct CR{
	char *course;
	char *room;
}CR_Relation;


CSG_Relation* new_CSG(char *C, char *S, char *G);
SNAP_Relation* new_SNAP(char *S, char *N, char *A, char *P);
CP_Relation* new_CP(char *C, char *P);
CDH_Relation* new_CDH(char *C, char *D, char *H);
CR_Relation* new_CR(char *C, char *R);
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
void print_CSG(LinkedList csgTuples);
void print_SNAP(LinkedList snapTuples);
void print_CP(LinkedList cpTuples);
void print_CDH(LinkedList cdhTuples);
void print_CR(LinkedList crTuples);
#endif