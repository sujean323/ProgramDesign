#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define NAME_LENGTH 50

struct node{
    char name[NAME_LENGTH];
    struct node *next;
    struct node *prev;
};

struct node *create(int n){
    struct node *tmp = NULL;
    struct node *tail = NULL;
    //create firstNode
    struct node *firstNode = (struct node*)malloc(sizeof(struct node));
    scanf("%s ",firstNode->name);
    firstNode->next = NULL;
    firstNode->prev = NULL;
    struct node *preNode = firstNode;
    //link all the nodes
    for(int i=0; i<n-1; i++){
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%s ", newNode->name);
        newNode->next = NULL;
        newNode->prev = preNode;
        (newNode->prev)->next = newNode;
        preNode = newNode;
        //link the last node to the first node
        if(i==n-2){
             (newNode->next) = firstNode;
            firstNode->prev = newNode;
        }
    }
    return firstNode;
}
void josephus(struct node *head, int n, int k, int flag){
    int count = 0; //how many people are killed
    struct node *p = head;
    while(n-count != 1){
        if(flag==1){
            //find person to be killed
            for(int i=0; i<k; i++){
                p = p->next;
            }
            printf("%s KILLED\n", p->name);
            (p->next)->prev = p->prev;
            (p->prev)->next = p->next;
            count++;
            p = p->next;
        }
        else if(flag==0){
            for(int i=0; i<k; i++){
                p = p->prev;
            }
            printf("%s KILLED\n", p->name);
            (p->next)->prev = p->prev;
            (p->prev)->next = p->next;
            count++;
            p = p->prev;
        }
    }
    printf("%s SURVIVE\n", p->name);
}
int main(){
    char dir[20];
    int n, k, flag;
    scanf("%d", &n); //n people in the circle
    struct node *head = create(n);
    scanf("%d %s", &k, dir); //num of the step and direction
    if(strcmp(dir, "CLOCKWISE")==0) flag = 1;
    else flag = 0;
    josephus(head, n, k, flag);

    return 0;
}

