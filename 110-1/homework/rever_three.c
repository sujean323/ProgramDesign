/*Extend the program above to handle three-digit numbers.*/

#include <stdio.h>

int main(void){
    int number;

    printf("Enter a three-digit number: ");
    scanf("%d", &number);
    printf("The number with its digits reversed is %d%d%d\n",(number%100)%10 ,(number%100)/10 , number/100);

    return 0;
}
