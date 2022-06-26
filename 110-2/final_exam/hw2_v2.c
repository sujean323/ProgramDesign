/*
#include<stdio.h>
#inclue<stdlib.h>
#define NAME_LENGTH 50
struct course{
    char name[NAME_LENGTH];
    struct course *next;
    struct course *prior;
};
void add()

int main(){
    int course_num, course_id, next_id, prior_id;
    struct course *head = NULL;
    struct course *t;

    scanf("%d", &course_num);
    scanf("%d %d %d %s", &cour)

}
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME_LENGTH 50

struct course{
    char name[NAME_LENGTH]; //represents the course name
    //struct course *t;
    struct course *next; //points to the next course
    struct course *prior; //points to the prerequisite course
    //int course_id;
    //int next_id;
    //int prior_id;
};
struct c{
    struct course a;
    struct course *t;
    int course_id;
    int next_id;
    int prior_id;
};
struct find{
    char course_name[NAME_LENGTH];
    int course_id;
    int next_id;
    int prior_id;
};
void create(struct c **head , int course_num, struct find find[], int i){
    struct c *tail = *head;
    struct c *tmp = NULL;
    tmp = (struct c*)malloc(course_num*sizeof(struct c));
    if(*head == NULL){
            strcpy(tmp->a.name, find[i].course_name);
            tmp->a.next = NULL;
            tmp->a.prior = NULL;
            tmp->t = NULL;
            tmp->course_id = find[i].course_id;
            tmp->next_id = find[i].next_id;
            tmp->prior_id = find[i].prior_id;
            *head = tmp;
    }
    else if(tail != NULL){
            while(tail->t != NULL){
                tail = tail->t;
            }
            strcpy(tmp->a.name, find[i].course_name);
            tmp->a.next = NULL;
            tmp->a.prior = NULL;
            tmp->t = NULL;
            tmp->course_id = find[i].course_id;
            tmp->next_id = find[i].next_id;
            tmp->prior_id = find[i].prior_id;
            tail->t = tmp;
    }
}

void next_list(struct c **head, int course_num){
        struct c *tail = *head;
        struct c *tmp = *head;
        int k = 0;
        for( int i = 0;tail != NULL ; tail=tail->t){
            for(tmp = *head ;tmp != NULL; tmp=tmp->t){
                if(tmp->course_id == tail->next_id){
                    tail->a.next = tmp;
                    k =1;
                    break;
                }
            }
            if(k!=1){
                tail->a.next=NULL;
            }
        }

}

void prior_list(struct c ** head, int course_num){
    struct c *tail = *head;
    struct c *tmp = *head;
    int k = 0;
    for( ;tail != NULL ; tail=tail->t){
        for(tmp = *head ;tmp != NULL ; tmp=tmp->t){
            if(tmp->course_id == tail->prior_id){
                tail->a.prior = tmp;
                k =1;
                break;
            }
        }
        if(k!=1){
            tail->a.prior=NULL;
        }
    }
}
int main(){
    int course_num;
    struct c* head = NULL;
    scanf("%d", &course_num);
    struct find find[course_num];
    for(int i=0; i<course_num; i++){
        scanf("%d %d %d %s", &find[i].course_id, &find[i].next_id, &find[i].prior_id, find[i].course_name);
    }
    for(int i = 0; i < course_num;i++)
        create(&head, course_num,find,i);

    //for(int i=0; i<=course_num; i++){
        next_list(&head, course_num);
    //}
    prior_list(&head, course_num);
    struct course *tmp = head;
    char choice;
    printf("Current Course: %s\n", tmp->name);
    printf("[n] Next course. [p] Prior course [q] Quit:");
    while(1){
        scanf("%c", &choice);
        if(choice == 'n'){
            if(tmp->next == NULL){
                printf("There is no next course.\n");
            }
            else if(tmp->next != NULL){
                tmp = tmp->next;
            }
            printf("Current Course: %s\n", tmp->name);
            printf("[n] Next course. [p] Prior course [q] Quit:");
        }
        else if(choice == 'p'){
            if(tmp->prior == NULL){
                printf("There is no previous course.\n");
            }
            else if(tmp->prior != NULL){
                tmp = tmp->prior;
            }
            printf("Current Course: %s\n", tmp->name);
            printf("[n] Next course. [p] Prior course [q] Quit:");
        }
        else if(choice == 'q'){
            exit(0);
        }
    }

    return 0;
}
