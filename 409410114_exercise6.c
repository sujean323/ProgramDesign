#include<stdio.h>
#include<ctype.h>

int main(){
    float value = 0;
    float num;
    char ch;//user input

    printf("Enter an expression: \n");
    scanf("%f", &value);//the first number of the expression

    while(1){
        ch = getchar();//read +-*/
        scanf("%f", &num);//read from second number of expression

        if(ch == '\n'){
            break;
        }//until read enter then stop read

        //determine the arithmetic
        switch(ch){
            case '+' :
                value += (float)num;
                break;
            case '-' :
                value -= (float)num;
                break;
            case '*' :
                value *= (float)num;
                break;
            case '/' :
                value /= (float)num;
                break;
        }
    }

    printf("Value of expression: %.2f\n", value);//print the result

    return 0;
}
