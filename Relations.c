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
	if(LinkedList_contains(db->csg, csg)) {
		printf("ERROR: Duplicate tuple");
	}

LinkedList_add_at_end(db->csg, csg);
}

void insert_SNAP(DB db, SNAP_Relation snap) {

}

void insert_CP(DB db, CP_Relation cp) {

}

void insert_CDH(DB db, CDH_Relation cdh) {

}

void insert_CR(DB db, CR_Relation cr) {

}

void delete_CSG(DB db, char *C, char *S, char *G) {

}

void delete_SNAP(DB db, char *S, char *N, char *A, char *P) {

}

void delete_CP(DB db, char *C, char *P){

}

void delete_CDH(DB db, char *C, char *D, char *H){

}

void delete_CR(DB db, char *C, char *R){

}

void lookup_CSG(DB db, char *C, char *S, char *G){

}

void lookup_SNAP(DB db, char *S, char *N, char *A, char *P){

}

void lookup_CP(DB db, char *C, char *P){

}

void lookup_CDH(DB db, char *C, char *D, char *H){

}

void lookup_CR(DB db, char *C, char *P){

}
