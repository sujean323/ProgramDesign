#include<stdio.h>

//declare function
void push(int* top_ptr, int size, int stack[]);
void pop(int* top_ptr, int stack[]);
void display(int* top_ptr, int stack[]);
int choice(int* top_ptr, int size, int stack[]);

//function code
void push(int* top_ptr, int size, int stack[]){
    int i;//pushed item
    if ((*top_ptr) > size-1){
        printf("stack overflow\n");
        display(top_ptr, stack);
    }
    else{
        printf("Enter the item to be pushed : ");
        scanf("%d", &i);

        stack[*top_ptr] = i;
        (*top_ptr)++;
        display(top_ptr, stack);
    }
    return;
}
void pop(int* top_ptr, int stack[]){
    if(*top_ptr <= 0){
        printf("stack underflow\n");
        display(top_ptr, stack);
    }
    else {
        printf("Element %d has been popped from the stack\n", stack[(*top_ptr)-1]);
        (*top_ptr)--;
        display(top_ptr, stack);
    }
    return;
}
void display(int* top_ptr, int stack[]){
    if(*top_ptr>0){
        for(int i=(*top_ptr)-1; i>=0; i--){
            printf("->%d\n",stack[i]);
        }
    }
    else
        printf("stack is empty\n");
}
int choice(int* top_ptr, int size, int stack[]){
    int choice;
    while(1){
        printf("1.Push 2.Pop 3.Display 4.Exit: ");
        scanf("%d", &choice);

        if(choice == 1){
            push(top_ptr, size, stack);
            //*top_ptr++;
        }
        else if(choice == 2){
            pop(top_ptr, stack);
            //if(*top_ptr>0)
                //*top_ptr--;
        }
        else if(choice == 3){
            //*top_ptr--;
            display(top_ptr, stack);
        }
        else if(choice == 4){
            return 0;
        }
        else
            printf("Invalid Choice\n");
    }
}
int main(){
    int size;//stack size
    int top =0;//the stack is empty
    int* top_ptr = &top;

    printf("Enter the size of the stack : ");
    scanf("%d", &size);//input
    int stack[size];

    choice(top_ptr, size, stack);

    return 0;
}
