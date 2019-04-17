#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.c"
#include "Database.c"
#include "Relations.c"


int main(void){
    DB *db = newDatabase();

    
    //Populate tables
    CSG_Relation *csg1 = new_CSG("CS101", "12345", "A");
    printf("\nNew CSG Tuple created: ('%s', '%s', '%s') \n", csg1->course, csg1->SID, csg1->grade);
    CSG_Relation *csg2 = new_CSG("CS101", "67890", "B");
    printf("New CSG Tuple created: ('%s', '%s', '%s') \n", csg2->course, csg2->SID, csg2->grade);
    CSG_Relation *csg3 = new_CSG("EE200", "12345", "C");
    printf("New CSG Tuple created: ('%s', '%s', '%s') \n", csg3->course, csg3->SID, csg3->grade);
    CSG_Relation *csg4 = new_CSG("EE200", "12345", "B+");
    printf("New CSG Tuple created: ('%s', '%s', '%s') \n", csg4->course, csg4->SID, csg4->grade);
    CSG_Relation *csg5 = new_CSG("CS101", "12345", "A-");
    printf("New CSG Tuple created: ('%s', '%s', '%s') \n", csg5->course, csg5->SID, csg5->grade);
    CSG_Relation *csg6 = new_CSG("PH100", "67890", "C+");
    printf("New CSG Tuple created: ('%s', '%s', '%s') \n", csg6->course, csg6->SID, csg6->grade);
    
    printf("\n");

    insert_CSG(db, csg1);
    insert_CSG(db, csg2);
    insert_CSG(db, csg3);
    insert_CSG(db, csg4);
    insert_CSG(db, csg5);
    insert_CSG(db, csg6); 

    print_CSG(db);

    printf("\n");

    delete_CSG(db, "CS101", "A", "A");

    

    //Example 8.2 Functions

    //lookup_CSG(db, "CS101", "12345", "*");
    //lookup_CP(db, "CS101","*");
    //delete_CR(db, "CS101", "*");
    //insert_CP(db, "CS101", "CS120");
    //insert_CP(db, "CS205", "CS205");

}
