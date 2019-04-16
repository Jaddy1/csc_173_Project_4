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
	int SID;
	char name[15];
	char address[20]; //address of the student
	int pNumber;	//phone number
};

struct Prerequisite{//course and its prerequisite
	char course[5];
	char prereq[5]; //prerequisite of the course
};

struct Cour_Day_Hour{
	char course[5];
	char day[2];	//day of the week
	char time[4];	//time of the class
};

struct Course_Room{
	char course[5];
	char room[15];
};
