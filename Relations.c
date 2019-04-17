#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "Relations.h"
#include "Database.h"

CSG_Relation* new_CSG(char *C, int S, char *G) {
	CSG_Relation *csg = malloc(sizeof(struct CSG));

	strcpy(csg->course, C);
	csg->SID = S;
	strcpy(csg->grade, C);

	return csg;
}

void insert_CSG(DB *db, CSG_Relation *csg) {
	if (LinkedList_contains(db->csg, csg)) {
		printf("ERROR: Duplicate tuple\n");
	}
	LinkedList_add_at_end(db->csg, csg);
    printf("Inserted CSG in the database\n");
}

void insert_SNAP(DB *db, SNAP_Relation *snap) {
	if (LinkedList_contains(db->snap, snap)) {
		printf("ERROR: Duplicate tuple");
	}else{
		LinkedList_add_at_end(db->snap, snap);
        printf("Inserted SNAP in the database\n");
	}
}

void insert_CP(DB *db, CP_Relation *cp) {
	if (LinkedList_contains(db->cp, cp)) {
		printf("ERROR: Duplicate tuple");
	} else {
		LinkedList_add_at_end(db->cp, cp);
        printf("Inserted CP into the database");
	}
}

void insert_CDH(DB *db, CDH_Relation *cdh) {
	if (LinkedList_contains(db->cp, cdh)) {
		printf("ERROR: Duplicate tuple");
	} else {
		LinkedList_add_at_end(db->cdh, cdh);
        printf("Inserted CDH into the database");
	}
}

void insert_CR(DB *db, CR_Relation *cr) {
	if (LinkedList_contains(db->cr, cr)) {
		printf("ERROR: Duplicate tuple");
	} else {
		LinkedList_add_at_end(db->cr, cr);
        printf("Inserted CR into the database");
	}
}

void delete_CSG(DB *db, char *C, char *S, char *G) {

}

void delete_SNAP(DB *db, char *S, char *N, char *A, char *P) {

}

void delete_CP(DB *db, char *C, char *P) {

}

void delete_CDH(DB *db, char *C, char *D, char *H) {

}

void delete_CR(DB *db, char *C, char *R) {

}

void lookup_CSG(DB *db, char *C, char *S, char *G) {

}

void lookup_SNAP(DB *db, char *S, char *N, char *A, char *P) {

}

void lookup_CP(DB *db, char *C, char *P) {

}

void lookup_CDH(DB *db, char *C, char *D, char *H) {

}

void lookup_CR(DB *db, char *C, char *P) {

}
