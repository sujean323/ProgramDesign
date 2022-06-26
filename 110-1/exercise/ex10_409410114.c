#include<stdio.h>

//declare function
void push(int top, int size, int stack[]);
void pop(int top, int stack[]);
void display(int top, int stack[]);
int choice(int top, int size, int stack[]);

//function code
void push(int top, int size, int stack[]){
    int i;//pushed item
    if (top > size-1){
        printf("stack overflow\n");
        display(top, stack);
    }
    else{
        printf("Enter the item to be pushed : ");
        scanf("%d", &i);

        stack[top] = i;
        top++;
        display(top, stack);
    }
    return;
}
void pop(int top, int stack[]){
    if(top <= 0){
        printf("stack underflow\n");
        display(top, stack);
    }
    else {
        printf("Element %d has been popped from the stack\n", stack[top-2]);
        display(top-2, stack);
    }
    return;
}
void display(int top, int stack[]){
    if(top>0){
        for(int i=top-1; i>=0; i--){
            printf("->%d\n",stack[i]);
        }
    }
    else
        printf("stack is empty\n");
}
int choice(int top, int size, int stack[]){
    int choice;
    while(1){
        printf("1.Push 2.Pop 3.Display 4.Exit: ");
        scanf("%d", &choice);

        if(choice == 1){
            push(top, size, stack);
            top++;
        }
        else if(choice == 2){
            pop(top, stack);
            if(top>0)
                top--;
        }
        else if(choice == 3){
            top--;
            display(top, stack);
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
    int top = 0;//the stack is empty
    int stack[size];
    printf("Enter the size of the stack : ");
    scanf("%d", &size);//input

    printf("%d\n", top);
    choice(top, size, stack);
    printf("%d\n", top);

    return 0;
}
