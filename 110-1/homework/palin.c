#include<stdio.h>

int reverse(int input){
    int tmp;
    static int ans = 0;
    if(input != 0){
        tmp = input%10;
        ans = ans*10 + tmp;
        reverse(input/10);
    }
    else
        return ans;
}
int main(){
    int input;
    scanf("%d", &input);

    if(input == reverse(input)){
        printf("palindrome");
    }
    else{
        printf("not palindrome");
    }
    return 0;
}
