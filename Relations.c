#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedList.h"
#include "Relations.h"
#include "Database.h"

CSG_Relation* new_CSG(char *C, char *S, char *G) {
	CSG_Relation *csg = (CSG_Relation *)malloc(sizeof(struct CSG));

	csg->course = C;
	csg->SID = S;
	csg->grade = G;

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
		printf("ERROR: Duplicate tuple \n");
	}else{
		LinkedList_add_at_end(db->snap, snap);
        printf("Inserted SNAP in the database\n");
	}
}

void insert_CP(DB *db, CP_Relation *cp) {
	if (LinkedList_contains(db->cp, cp)) {
		printf("ERROR: Duplicate tuple \n");
	} else {
		LinkedList_add_at_end(db->cp, cp);
        printf("Inserted CP into the database \n");
	}
}

void insert_CDH(DB *db, CDH_Relation *cdh) {
	if (LinkedList_contains(db->cp, cdh)) {
		printf("ERROR: Duplicate tuple \n");
	} else {
		LinkedList_add_at_end(db->cdh, cdh);
        printf("Inserted CDH into the database \n");
	}
}

void insert_CR(DB *db, CR_Relation *cr) {
	if (LinkedList_contains(db->cr, cr)) {
		printf("ERROR: Duplicate tuple \n");
	} else {
		LinkedList_add_at_end(db->cr, cr);
        printf("Inserted CR into the database \n");
	}
}

void delete_CSG(DB *db, char *C, char *S, char *G) {
    LinkedList csg = db->csg;
    LinkedListIterator it = LinkedList_iterator(csg);
    char *ASTERISK = "A";

    printf("Delete Specification: ('%s', '%s', '%s') \n", C, S, G);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CSG_Relation *rel = data;
        printf("Current tuple (%s, %s, %s) \n", rel->course, rel->SID, rel->grade);

        bool Cmatches = (rel->course == C || C == ASTERISK);
        bool Smatches = (rel->SID == ASTERISK || S == ASTERISK);
        bool Gmatches = (rel->grade == ASTERISK || G == ASTERISK);

        printf("%d %d %d \n", Cmatches, Smatches, Gmatches);

        if(Cmatches && Smatches && Gmatches) {
            LinkedList_remove(csg, rel);
            printf("Deleted tuple: Course = %s, StudentID = %s, Grade = %s \n", rel->course, rel->SID, rel->grade);
        }
    }

    printf("\nNew Relation: \n");
    //LinkedList_print_string_list(csg); //Doesn't print info in tuples but can be used to see how many tuples are present
    print_CSG(db);

    free(it);
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

void print_CSG(DB *db) {
    LinkedList csgTuples = db->csg;
    LinkedListIterator it = LinkedList_iterator(csgTuples);
    int tupleCount = 0;

    printf("\nCSG RELATION\n");

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CSG_Relation *rel = data;
        tupleCount++;

        printf("Tuple %d: (%s, %s, %s) \n", tupleCount, rel->course, rel->SID, rel->grade);

    }
}

void print_SNAP(DB db) {
    
}
void print_CDH(DB db) {
    
}
void print_CP(DB db) {
    
}
void print_CR(DB db) {
    
}
