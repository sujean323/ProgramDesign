#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void display();             //  功能皆如函式名
void finish();              
void push();
void pop();
void display();
void action();
bool is_full();
bool is_empty();
//***********************************************************
int main(){
	int N;					//  STACK 大小
	int top = -1;			//  STACK 的頂端
	printf("Enter the size of the stack: ");
	scanf("%d", &N);
	printf("\n");
	int contents[100000];
    action(top,N,contents);
    return 0;
}
//************************************************************
bool is_full(int top,int N){
	if(top+1>=N){
		return 1;
	}
	return 0;
}
//************************************************************
bool is_empty(int top){
	if(top<0){
		return 1;
	}
	else{
		return 0;
	}
}
//*************************************************************
void action(int top,int N,int contents){
    int choose;
    int input;        //  要 push 的數
    while(1){
		printf("1.Push 2.Pop 3.Display 4.Exit: ");
		scanf("%d", &choose);
		printf("\n");
        switch(choose){
			case 1:
				if(is_full(top,N)){
					printf("Stack overflow\n\n");
					display(top,contents);
					continue;
				}
				printf("Enter the item to be pushed: ");
				scanf("%d", &input);
				printf("\n");
				++top;
				push(top,N,contents,input);
				break;
			case 2:
				if(is_empty(top)){
					printf("Stack underflow\n\n");
					display(top, contents);
					continue;
				}
				pop(top, contents);
				--top;
				break;
			case 3:
				display(top,contents);
				break;
			case 4:
				finish();
				break;
			default:
				printf("Invalid Choice\n\n");
		}
	}
}
//**************************************************************
void push(int top,int N,int contents[],int input){
		contents[top] = input;
		display(top,contents);
}
//**************************************************************
void pop(int top,int contents[]){
		printf("Element %d has been popped from the stack\n\n", contents[top]);
		display(top-1,contents);
}
//**************************************************************
void display(int top,int contents[]){
	if(top<0){
		printf("Stack is empty\n\n");
	}
	for (int i = top; i >= 0;i--){
		printf(" -> %d\n\n", contents[i]);
	}
}
//**************************************************************
void finish(){
	exit(0);
}