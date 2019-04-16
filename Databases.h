#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TUPLE TUPLELIST;
struct TUPLE{
	int ID;
	char Name[30];
	char Address[50];
	char Phone[10];
	TUPLELIST next;
};

struct CSG{
	char course[5]; //course name
	int SID; //student ID
	char grade[2]; //grade the student received
};

struct SNAP{
	int SID;
	char name[15];
	char address[20];
	int pNumber;
};

struct Prerequisite{
	char course[5];
	char prerequ[5];
};

struct Cour_Day_Hour{
	char course[5];
	char day[2];
	char time[4];
};

struct Course_Room{
	char course[5];
	char room[15];
};
