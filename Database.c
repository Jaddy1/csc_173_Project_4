#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedList.h"
#include "Relations.h"
#include "Database.h"
#include "LinkedList.h"

//typedef TUPLELIST Course-Prerequisite[1009];


DB* newDatabase() {
	LinkedList csg =  new_LinkedList();
	LinkedList snap =  new_LinkedList();
	LinkedList cp =  new_LinkedList();
	LinkedList cdh =  new_LinkedList();
	LinkedList cr =  new_LinkedList();

	DB *db = malloc(sizeof(struct Database));
	db->csg = csg;
	db->snap = snap;
	db->cp = cp;
	db->cdh = cdh;
	db->cr = cr;

	return db;
}