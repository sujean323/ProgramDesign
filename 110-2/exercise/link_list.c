#include "myDS.h"
#include "basic.h"

// HEAD is point to FOODPAPA (id: 0)
void my_insert(struct node* HEAD, int ID, char *Name, int node_id){
    // Please insert a new node(store Name & node_id)
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    struct node *tmp = HEAD;
    // after the node which id is ID
    // If it doesn't exit such ID, print "INVALID OPERATION"
	while(tmp != NULL && tmp->id != ID){
        tmp = tmp->next;
	}
	if(tmp == NULL){
        printf("INVALID OPERATION\n");
	}
	else{
        newNode->id = node_id;
        strcpy(newNode->name, Name);
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}
void my_delete(struct node* HEAD, char *Name){
	// Delete the node which store the Name.
	struct node *tmp = HEAD;
	struct node *prev = HEAD;
	while(tmp != NULL && strcmp(tmp->name, Name)!=0){
        prev = tmp;
        tmp = tmp->next;
	}
	// If it doesn’t exit such Name, print “INVALID OPERATION”.
	if(tmp == NULL){
        printf("INVALID OPERATION\n");
        return;
	}
	prev->next = tmp->next;
	free(tmp);
}
void my_swap(struct node *HEAD, char *Name1, char *Name2){
	// Swap the node which store Name1 and Name2
	struct  node *prev1 = NULL;
	struct node *cur1 = HEAD;
	while(cur1 != NULL && strcmp(cur1->name, Name1)!= 0){
        prev1 = cur1;
        cur1 = cur1->next;
	}
	struct node *prev2 = NULL;
	struct node *cur2 = HEAD;
    while(cur2 != NULL && strcmp(cur2->name, Name2) != 0){
        prev2 = cur2;
        cur2 = cur2->next;
	}
	// If either of the node doesn’t exit, print “INVALID OPERATION”
	if(cur1 == NULL || cur2 == NULL){
        printf("INVALID OPERATION\n");
	}
	// NOTICE: don't just swap the node's value
	// You need to break the link and recombine it
	else{
		prev1->next = cur2;
		prev2->next = cur1;
    	struct node *tmp = cur2->next;
    	cur2->next = cur1->next;
    	cur1->next = tmp;
	}
}
void my_print_id(struct node *HEAD, char *Name){
	// Print the id of the corresponding Name.
	struct node *tmp = HEAD;
	while(tmp != NULL && strcmp(tmp->name, Name)){
            tmp = tmp->next;
	}
	// If ID doesn’t exit, print “INVALID OPERATION”
    if(tmp == NULL){
        printf("INVALID OPERATION\n");
        return;
	}
	printf("%d\n", tmp->id);
	// If Name doesn’t exit, print “INVALID OPERATION”
}
void my_print_name(struct node *HEAD, int ID){
	// Print the name of the corresponding ID
    struct node *tmp = HEAD;
	while(tmp != NULL && tmp->id != ID){
            tmp = tmp->next;
	}
	// If ID doesn’t exit, print “INVALID OPERATION”
    if(tmp == NULL){
        printf("INVALID OPERATION\n");
        return;
	}
	printf("%s\n", tmp->name);
}
void my_result(struct node* HEAD){
	// Print out all the information in the linked list orderly
	struct node *tmp = HEAD;
	while(tmp != NULL){
        printf("%d %s\n", tmp->id, tmp->name);
        tmp = tmp->next;
	}
	// in the format “ID NAME”. (start from HEAD)
}

