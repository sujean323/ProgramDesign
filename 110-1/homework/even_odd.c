#include<stdio.h>

void even_odd(int x, int input){
    if(x>input)
        return;
    printf("%d ", x);
    even_odd(x+2, input);
}
int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);

    even_odd(2, input);
    printf("\n");
    even_odd(1, input);

    return 0;
}
/*
    for(int i=1; i<=input; i++){
        if(input%2 == 0){
            printf("%d", i);
        }
        else
            return even(input);
    }
*/
