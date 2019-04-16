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

struct Prerequisite{
	char couse[5];
	char prerequ[5];
};

struct Course_Room{
	char course[5];
	char room[15];
};
