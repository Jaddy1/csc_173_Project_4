#ifndef ALGEBRA_H_
#define ALGEBRA_H_

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "Relations.h"
#include "LinkedList.h"
#include "Database.h"

LinkedList select_CSG(DB *db, bool C, bool S, bool G, char *value);
LinkedList select_SNAP(DB *db, bool S, bool N, bool A, bool P, char *value);
LinkedList select_CP(DB *db, bool C, bool P, char *value);
LinkedList select_CDH(DB *db, bool C, bool D, bool H, char *value);
LinkedList select_CR(DB *db, bool C, bool R, char *value);

LinkedList project_CSG(LinkedList list, bool C, bool S, bool G);
LinkedList project_SNAP(LinkedList list, bool S, bool N, bool A, bool P);
LinkedList project_CP(LinkedList list, bool C, bool P);
LinkedList project_CDH(LinkedList list, bool C, bool D, bool H);
LinkedList project_CR(LinkedList list, bool C, bool R);

#endif