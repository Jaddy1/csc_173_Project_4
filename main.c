#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "LinkedList.c"
#include "Database.c"
#include "Relations.c"
#include "Algebra.c"

int main(void)
{
    //Creates new database    
    DB *db = newDatabase();

    //Populate CSG tables
    CSG_Relation *csg1 = new_CSG("CS101", "12345", "A");
    CSG_Relation *csg2 = new_CSG("CS101", "67890", "B");
    CSG_Relation *csg3 = new_CSG("EE200", "12345", "C");
    CSG_Relation *csg4 = new_CSG("EE200", "12345", "B+");
    CSG_Relation *csg5 = new_CSG("CS101", "33333", "A-");
    CSG_Relation *csg6 = new_CSG("PH100", "67890", "C+");

    //Populate SNAP tables
    SNAP_Relation *snap1 = new_SNAP("12345", "C. Brown", "12 Apple St.", "555-1234");
    SNAP_Relation *snap2 = new_SNAP("67890", "L. Van Pelt", "34 Pear Ave.", "555-5678");
    SNAP_Relation *snap3 = new_SNAP("22222", "P. Patty", "56 Grape Blvd.", "555-9999");

    //Populate CP tables
    CP_Relation *cp1 = new_CP("CS101", "CS100");
    CP_Relation *cp2 = new_CP("EE200", "EE005");
    CP_Relation *cp3 = new_CP("EE200", "CS100");
    CP_Relation *cp4 = new_CP("CS120", "CS101");
    CP_Relation *cp5 = new_CP("CS121", "CS120");
    CP_Relation *cp6 = new_CP("CS205", "CS101");
    CP_Relation *cp7 = new_CP("CS206", "CS121");
    CP_Relation *cp8 = new_CP("CS206", "CS205");

    //Populate CDH tables
    CDH_Relation *cdh1 = new_CDH("CS101", "M", "9AM");
    CDH_Relation *cdh2 = new_CDH("CS101", "W", "9AM");
    CDH_Relation *cdh3 = new_CDH("CS101", "F", "9AM");
    CDH_Relation *cdh4 = new_CDH("EE200", "Tu", "10AM");
    CDH_Relation *cdh5 = new_CDH("EE200", "W", "1PM");
    CDH_Relation *cdh6 = new_CDH("EE200", "Th", "10AM");

    //Populate CR
    CR_Relation *cr1 = new_CR("CS101", "Turing Aud.");
    CR_Relation *cr2 = new_CR("EE200", "25 Ohm Hall");
    CR_Relation *cr3 = new_CR("PH100", "Newton Lab.");

    //Insert CSG into DB
    insert_CSG(db, csg1);
    insert_CSG(db, csg2);
    insert_CSG(db, csg3);
    insert_CSG(db, csg4);
    insert_CSG(db, csg5);
    insert_CSG(db, csg6);

    //Insert SNAP into DB
    insert_SNAP(db, snap1);
    insert_SNAP(db, snap2);
    insert_SNAP(db, snap3);

    //Insert CP into DB
    insert_CP(db, cp1);
    insert_CP(db, cp2);
    insert_CP(db, cp3);
    insert_CP(db, cp4);
    insert_CP(db, cp5);
    insert_CP(db, cp6);
    insert_CP(db, cp7);
    insert_CP(db, cp8);

    //Insert CDH into DB
    insert_CDH(db, cdh1);
    insert_CDH(db, cdh2);
    insert_CDH(db, cdh3);
    insert_CDH(db, cdh4);
    insert_CDH(db, cdh5);
    insert_CDH(db, cdh6);

    //Insert CR into DB
    insert_CR(db, cr1);
    insert_CR(db, cr2);
    insert_CR(db, cr3);

    //Print tables
    print_CSG(db->csg);
    print_SNAP(db->snap);
    print_CP(db->cp);
    print_CDH(db->cdh);
    print_CR(db->cr);

    //Example 8.2 functions
    //lookup_CSG(db, "CS101", "12345", "*");
    //lookup_CP(db, "CS101","*");
    delete_CR(db, "CS101", "*");
    insert_CP(db, new_CP("CS205", "CS120"));
    insert_CP(db, new_CP("CS205", "CS101"));

    //Example 8.12 Selection Function
    printf("\nSelect from CSG Where Course = 'CS101'\n");
    LinkedList selectedCSG = select_CSG(db, true, false, false, "CS101");
    print_CSG(selectedCSG);

    //Other examples of Selection Functions just for fun
    printf("\nSelect from CP Where Prerequisite = 'CS100'\n");
    LinkedList selectedCP = select_CP(db,false, true, "CS100");
    print_CP(selectedCP);

    printf("\nSelect from SNAP Where StudentId = '12345'\n");
    LinkedList selectedSNAP = select_SNAP(db, true, false, false, false, "12345");
    print_SNAP(selectedSNAP);

    printf("\nSelect from CDH Where Hour = '9AM'\n");
    LinkedList selectedCDH = select_CDH(db, false, false, true, "9AM");
    print_CDH(selectedCDH);

    printf("\nSelect from CR Where Room = 'Newton Lab.'\n");
    LinkedList selectedCR = select_CR(db, false, true,"Newton Lab.");
    print_CR(selectedCR);

    //Example 8.13 Projection Function
    printf("\nProject StudentIDs of Students that Take CS101\n\n");
    LinkedList projectedCSG = project_CSG(selectedCSG, false, true, false);
    LinkedList_print_string_list(projectedCSG);
}
