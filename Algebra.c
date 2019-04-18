#include "Algebra.h"
#include <stddef.h>

LinkedList select_CSG(DB *db, bool C, bool S, bool G, char *value) {
    LinkedList csg = db->csg; //list of csg tuples (structs)
    LinkedList newCSG = new_LinkedList();
    LinkedListIterator it = LinkedList_iterator(csg);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CSG_Relation *rel = data;

        if(C) {
            if(rel->course == value) {
                LinkedList_add_at_end(newCSG, new_CSG(rel->course, rel->SID, rel->grade));
            }
            
        } else if(S) {
            if(rel->SID== value) {
                LinkedList_add_at_end(newCSG, new_CSG(rel->course, rel->SID, rel->grade));
            }
        } else if(G) {
             if(rel->grade == value) {
                LinkedList_add_at_end(newCSG, new_CSG(rel->course, rel->SID, rel->grade));
            }
            

        }
    }

    return newCSG;
}

LinkedList select_SNAP(DB *db, bool S, bool N, bool A, bool P, char *value) {
    LinkedList snap = db->snap; //list of snap tuples (structs)
    LinkedList newSNAP = new_LinkedList();
    LinkedListIterator it = LinkedList_iterator(snap);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		SNAP_Relation *rel = data;

        if(S) {
            if(rel->SID == value) {
                LinkedList_add_at_end(newSNAP, new_SNAP(rel->SID, rel->name, rel->address, rel->pNumber));
            }
            
        } else if(N) {
            if(rel->name == value) {
                LinkedList_add_at_end(newSNAP, new_SNAP(rel->SID, rel->name, rel->address, rel->pNumber));
            }
        } else if(A) {
            if(rel->address == value) {
                LinkedList_add_at_end(newSNAP, new_SNAP(rel->SID, rel->name, rel->address, rel->pNumber));
            }
        } else if(P) {
            if(rel->pNumber == value) {
                LinkedList_add_at_end(newSNAP, new_SNAP(rel->SID, rel->name, rel->address, rel->pNumber));
            }
        }
    }

    return newSNAP;
}

LinkedList select_CP(DB *db, bool C, bool P, char *value) {
     LinkedList cp = db->cp; //list of cp tuples (structs)
    LinkedList newCP = new_LinkedList();
    LinkedListIterator it = LinkedList_iterator(cp);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CP_Relation *rel = data;

        if(C) {
            if(rel->course == value) {
                LinkedList_add_at_end(newCP, new_CP(rel->course, rel->prereq));
            }
            
        } else if(P) {
            if(rel->prereq== value) {
                LinkedList_add_at_end(newCP, new_CP(rel->course, rel->prereq));
            }
        }
    }

    return newCP;

}

LinkedList select_CDH(DB *db, bool C, bool D, bool H, char *value) {
    LinkedList cdh = db->cdh; //list of cdh tuples (structs)
    LinkedList newCDH = new_LinkedList();
    LinkedListIterator it = LinkedList_iterator(cdh);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CDH_Relation *rel = data;

        if(C) {
            if(rel->course == value) {
                LinkedList_add_at_end(newCDH, new_CDH(rel->course, rel->day, rel->hour));
            }
            
        } else if(D) {
            if(rel->day == value) {
                LinkedList_add_at_end(newCDH, new_CDH(rel->course, rel->day, rel->hour));
            }
        } else if(H) {
             if(rel->hour == value) {
                LinkedList_add_at_end(newCDH, new_CDH(rel->course, rel->day, rel->hour));
            }
        }
    }

    return newCDH;

}

LinkedList select_CR(DB *db, bool C, bool R, char *value) {
    LinkedList cr = db->cr; //list of cr tuples (structs)
    LinkedList newCR = new_LinkedList();
    LinkedListIterator it = LinkedList_iterator(cr);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CR_Relation *rel = data;

        if(C) {
            if(rel->course == value) {
                LinkedList_add_at_end(newCR, new_CR(rel->course, rel->room));
            }
            
        } else if(R) {
            if(rel->room == value) {
                LinkedList_add_at_end(newCR, new_CR(rel->course, rel->room));
            }
        } 
    }

    return newCR;

}

LinkedList project_CSG(LinkedList tuples, bool C, bool S, bool G) {
    LinkedList newCSG = new_LinkedList();
    LinkedListIterator it = LinkedList_iterator(tuples);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CSG_Relation *rel = data;

        if(C) {
            LinkedList_add_at_end(newCSG, rel->course);
        } else if(S) {
            LinkedList_add_at_end(newCSG, rel->SID);
        } else if(G) {
            LinkedList_add_at_end(newCSG, rel->grade);    
        }
    }

    return newCSG;
}

LinkedList project_SNAP(LinkedList tuples, bool S, bool N, bool A, bool P) {
    LinkedList newSNAP = new_LinkedList();
    LinkedListIterator it = LinkedList_iterator(tuples);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		SNAP_Relation *rel = data;

        if(S) {
            LinkedList_add_at_end(newSNAP, rel->SID);
        } else if(N) {
            LinkedList_add_at_end(newSNAP, rel->name);
        } else if(A) {
            LinkedList_add_at_end(newSNAP, rel->address);    
        } else if(P) {
            LinkedList_add_at_end(newSNAP, rel->pNumber);    
        }
    }

    return newSNAP;

}

LinkedList project_CP(LinkedList tuples, bool C, bool P) {
    LinkedList newCP = new_LinkedList();
    LinkedListIterator it = LinkedList_iterator(tuples);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CP_Relation *rel = data;

        if(C) {
            LinkedList_add_at_end(newCP, rel->course);
        } else if(P) {
            LinkedList_add_at_end(newCP, rel->prereq);
        } 
    }

    return newCP;

}

LinkedList project_CDH(LinkedList tuples, bool C, bool D, bool H) {
    LinkedList newCDH = new_LinkedList();
    LinkedListIterator it = LinkedList_iterator(tuples);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CDH_Relation *rel = data;

        if(C) {
            LinkedList_add_at_end(newCDH, rel->course);
        } else if(D) {
            LinkedList_add_at_end(newCDH, rel->day);
        } else if(H) {
            LinkedList_add_at_end(newCDH, rel->hour);    
        }
    }

    return newCDH;

}

LinkedList project_CR(LinkedList tuples, bool C, bool R) {
    LinkedList newCR = new_LinkedList();
    LinkedListIterator it = LinkedList_iterator(tuples);

    while(LinkedListIterator_hasNext(it)) {
        void *data = LinkedListIterator_next(it);
		CR_Relation *rel = data;

        if(C) {
            LinkedList_add_at_end(newCR, rel->course);
        } else if(R) {
            LinkedList_add_at_end(newCR, rel->room);
        }
    }

    return newCR;

}
