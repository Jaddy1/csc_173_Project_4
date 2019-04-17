#ifndef DATABASE_H
#define DATABASE_H

#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

struct Database{
	struct LinkedList *csg;
	struct LinkedList *snap;
	struct LinkedList *cp;
	struct LinkedList *cdh;
	struct LinkedList *cr;
};


typedef struct Database DB;

DB* newDatabase();
void printDatabase(DB db);

#endif