#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"LinkedList.h"
#include"Databases.h"

Database* Db_Lookup(Database *LB, char *c){
	char delim[] = ",";
	char *token;
	int addOn = 1;
	char *dst = strdup(c);

	Database *newdb = (Database*)malloc(sizeof(Database));
	newdb-> list = LinkedList_new();
	LinkedListIterator *itt = LinkedList_iterator(db-> list);
	LinkedList_add_at_end(newdb-> list, LinkedListIterator_next(itt));
	while(LinkedListIterator_has_next(itt)){
		addOn = 1;
		void *data = LinkedListIterator_next(itt);
		//Loops through larger array list
		dst = strdup(c);
		LinkedListIttorator *itTup = LinkedList_iterator(data);
		for (token = strtok(dst, delim); token; token = strtok(NULL, delim)){
			void *dataTup = LinkedListIterator_next(itTup);
			char *str = (char*)dataTup;
			//loops through individual linked lists
			if(strcmp(token, "*") != 0){
				if(strcmp(token, str)!= 0){
					addOn = 0;
					break;
					//adds an iterator for the linked list, iterate through the linked list then put matches into a new database
					//when you reach a "*" break, if not continue
				}
			}

		}
		if(addOn == 1){
			LinkedList_add_at_end(newdb-> list, data);
		}
		free(itTup);
	}
	free(itt);
	return newdb;
}
