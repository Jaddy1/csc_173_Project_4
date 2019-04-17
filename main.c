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
    CSG_Relation *csg2 = new_CSG("CS101", "67890", "B");
    CSG_Relation *csg3 = new_CSG("EE200", "12345", "C");
    CSG_Relation *csg4 = new_CSG("EE200", "12345", "B+");
    CSG_Relation *csg5 = new_CSG("CS101", "12345", "A-");
    CSG_Relation *csg6 = new_CSG("PH100", "67890", "C+");
    insert_CSG(db, csg1);
    insert_CSG(db, csg2);
    insert_CSG(db, csg3);
    insert_CSG(db, csg4);
    insert_CSG(db, csg5);
    insert_CSG(db, csg6); 

    delete_CSG(db, "CS101", "*", "*");

    

    //Example 8.2 Functions

    //lookup_CSG(db, "CS101", 12345, "*");
    //lookup_CP(db, "CS101", 12345, "*");
    //delete_CR(db, "CS101", "*");
    //insert_CP(db, "CS101", "CS120");
    //insert_CP(db, "CS205", "CS205");

}
