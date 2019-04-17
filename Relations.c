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

SNAP_Relation* new_SNAP(char *S, char *N, char *A, char *P) {
	SNAP_Relation *snap = (SNAP_Relation *)malloc(sizeof(struct SNAP));

	snap->SID = S;
	snap->name = N;
	snap->address = A;
    snap->pNumber = P;

	return snap;
}

CP_Relation* new_CP(char *C, char *P) {
	CP_Relation *cp = (CP_Relation *)malloc(sizeof(struct CP));

	cp->course = C;
	cp->prereq = P;

	return cp;
}

CDH_Relation* new_CDH(char *C, char *D, char *H) {
	CDH_Relation *cdh = (CDH_Relation *)malloc(sizeof(struct CDH));

	cdh->course = C;
	cdh->day = D;
	cdh->hour = H;

	return cdh;
}

CR_Relation* new_CR(char *C, char *R) {
	CR_Relation *cr = (CR_Relation *)malloc(sizeof(struct CR));

	cr->course = C;
	cr->room = R;

	return cr;
}

void insert_CSG(DB *db, CSG_Relation *csg) {
	if (LinkedList_contains(db->csg, csg)) {
		printf("ERROR: Duplicate tuple\n");
	}
	LinkedList_add_at_end(db->csg, csg);
    printf("\nInserted CSG in the database\n");
    print_CSG(db);
}

void insert_SNAP(DB *db, SNAP_Relation *snap) {
	if (LinkedList_contains(db->snap, snap)) {
		printf("ERROR: Duplicate tuple \n");
	}else{
		LinkedList_add_at_end(db->snap, snap);
        printf("\nInserted SNAP in the database\n");
        print_SNAP(db);
	}
}

void insert_CP(DB *db, CP_Relation *cp) {
	if (LinkedList_contains(db->cp, cp)) {
		printf("ERROR: Duplicate tuple \n");
	} else {
		LinkedList_add_at_end(db->cp, cp);
        printf("\nInserted CP into the database \n");
        print_CP(db);
	}
}

void insert_CDH(DB *db, CDH_Relation *cdh) {
	if (LinkedList_contains(db->cp, cdh)) {
		printf("ERROR: Duplicate tuple \n");
	} else {
		LinkedList_add_at_end(db->cdh, cdh);
        printf("\nInserted CDH into the database \n");
        print_CDH(db);
	}
}

void insert_CR(DB *db, CR_Relation *cr) {
	if (LinkedList_contains(db->cr, cr)) {
		printf("ERROR: Duplicate tuple \n");
	} else {
		LinkedList_add_at_end(db->cr, cr);
        printf("\nInserted CR into the database \n");
        print_CR(db);
	}
}

void delete_CSG(DB *db, char *C, char *S, char *G) {
    LinkedList csg = db->csg;
    LinkedListIterator it = LinkedList_iterator(csg);
    char *ASTERISK = "*";

    printf("\n Delete Specification: ('%s', '%s', '%s') \n", C, S, G);

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

    printf("\nUpdated CSG Relation: \n");
    print_CSG(db);

    free(it);
}

void delete_SNAP(DB *db, char *S, char *N, char *A, char *P) {
    LinkedList snap = db->snap;
    LinkedListIterator it = LinkedList_iterator(snap);
    char *ASTERISK = "*";

    printf("\n Delete Specification: ('%s', '%s', '%s', '%s') \n", S, N, A, P);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		SNAP_Relation *rel = data;
        printf("Current tuple (%s, %s, %s, %s) \n", rel->SID, rel->name, rel->address, rel->pNumber);

        bool Smatches = (rel->SID== S || S == ASTERISK);
        bool Nmatches = (rel->name == ASTERISK || N == ASTERISK);
        bool Amatches = (rel->address == ASTERISK || A == ASTERISK);
        bool Pmatches = (rel->pNumber == ASTERISK || P == ASTERISK);

        if(Smatches && Nmatches && Amatches && Pmatches) {
            LinkedList_remove(snap, rel);
            printf("Deleted tuple: StudentID = %s, Name = %s, Address = %s, Phone = %s \n", rel->SID, rel->name, rel->address, rel->pNumber);
        }
    }

    printf("\nUpdated SNAP Relation: \n");
    print_SNAP(db);

    free(it);

}

void delete_CP(DB *db, char *C, char *P) {
    LinkedList cp = db->cp;
    LinkedListIterator it = LinkedList_iterator(cp);
    char *ASTERISK = "*";

    printf("\nDelete Specification: ('%s', '%s') \n", C, P);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CP_Relation *rel = data;
        printf("Current tuple (%s, %s) \n", rel->course, rel->prereq);

        bool Cmatches = (rel->course == C || C == ASTERISK);
        bool Pmatches = (rel->prereq || P == ASTERISK);

        if(Cmatches && Pmatches) {
            LinkedList_remove(cp, rel);
            printf("Deleted tuple: Course = %s, Prerequisite = %s\n", rel->course, rel->prereq);
        }
    }

    printf("\nUpdated CP Relation: \n");
    print_CP(db);

    free(it);

}

void delete_CDH(DB *db, char *C, char *D, char *H) {
    LinkedList cdh = db->cdh;
    LinkedListIterator it = LinkedList_iterator(cdh);
    char *ASTERISK = "*";

    printf("\nDelete Specification: ('%s', '%s', '%s') \n", C, D, H);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CDH_Relation *rel = data;
        printf("Current tuple (%s, %s, %s) \n", rel->course, rel->day, rel->hour);

        bool Cmatches = (rel->course == C || C == ASTERISK);
        bool Dmatches = (rel->day== ASTERISK || D == ASTERISK);
        bool Hmatches = (rel->hour == ASTERISK || H == ASTERISK);

        if(Cmatches && Dmatches && Hmatches) {
            LinkedList_remove(cdh, rel);
            printf("Deleted tuple: Course = %s, Day = %s, Hour = %s \n", rel->course, rel->day, rel->hour);
        }
    }

    printf("\nUpdated CDH Relation: \n");
    print_CDH(db);

    free(it);

}

void delete_CR(DB *db, char *C, char *R) {
    LinkedList cr = db->cr;
    LinkedListIterator it = LinkedList_iterator(cr);
    char *ASTERISK = "*";

    printf("\nDelete Specification: ('%s', '%s') \n", C, R);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CR_Relation *rel = data;
        printf("Current tuple (%s, %s) \n", rel->course, rel->room);

        bool Cmatches = (rel->course == C || C == ASTERISK);
        bool Rmatches = (rel->room == ASTERISK || R == ASTERISK);

        if(Cmatches && Rmatches) {
            LinkedList_remove(cr, rel);
            printf("Deleted tuple: Course = %s, Room = %s \n", rel->course, rel->room);
        }
    }

    printf("\nUpdated CR Relation: \n");
    print_CR(db);

    free(it);

}

DB *lookup_CSG(DB *db, char *C, char *S, char G){
	DB *newDB = (DB)malloc(sizeof(DB));
	LinkedList csg = db->csg;
	LinkedListIterator *it = LinkedList_iterator(db->csg);
	char *ASTERISK = "A";

	while(LinkedListIterator_hasNext(it)){
		void *data = LinkedListIterator_next(it);
		CSG_Relation *rel = data;
		printf("Current tuple (%s, %s, %s)\n", rel->course, rel->SID, rel->grade);

		bool Cmatches = (rel->course == C || ASTERISK);
		bool Smatches = (rel ->SID == ASTERISK || S == ASTERISK);
		bool Gmatches = (rel->grade == ASTERISK || G == ASTERISK);

		printf("%d %d %d \n", Cmatches, Smatches, Gmatches);

		if(Cmatches && Smatches && Gmatches){
			LinkedList_add_at_end(csg, rel);
			printf("Added tuple: Course = %s, StudentID = %s, Grade = %s \n", rel->course, rel->SID, rel->grade);
		}
	}

	free(it);
	return newDB;
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

void print_SNAP(DB *db) {
    LinkedList snapTuples = db->snap;
    LinkedListIterator it = LinkedList_iterator(snapTuples);
    int tupleCount = 0;

    printf("\nSNAP RELATION\n");

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		SNAP_Relation *rel = data;
        tupleCount++;

        printf("Tuple %d: (%s, %s, %s, %s) \n", tupleCount, rel->SID, rel->name, rel->address, rel->pNumber);

    }

}
void print_CDH(DB *db) {
    LinkedList cdhTuples = db->cdh;
    LinkedListIterator it = LinkedList_iterator(cdhTuples);
    int tupleCount = 0;

    printf("\nCDH RELATION\n");

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CDH_Relation *rel = data;
        tupleCount++;

        printf("Tuple %d: (%s, %s, %s) \n", tupleCount, rel->course, rel->day, rel->hour);

    }

}
void print_CP(DB *db) {
    LinkedList cpTuples = db->cp;
    LinkedListIterator it = LinkedList_iterator(cpTuples);
    int tupleCount = 0;

    printf("\nCP RELATION\n");

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CP_Relation *rel = data;
        tupleCount++;

        printf("Tuple %d: (%s, %s) \n", tupleCount, rel->course, rel->prereq);

    }

}
void print_CR(DB *db) {
    LinkedList crTuples = db->cr;
    LinkedListIterator it = LinkedList_iterator(crTuples);
    int tupleCount = 0;

    printf("\nCR RELATION\n");

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CR_Relation *rel = data;
        tupleCount++;

        printf("Tuple %d: (%s, %s) \n", tupleCount, rel->course, rel->room);

    }

}
