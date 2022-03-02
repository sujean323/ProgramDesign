/*Write a program that asks the user to enter a dollar amount and then shows how
to pay the amount using the smallest number of $20, $10, $5, and $1 bills.
Hint: Divide the amount by 20 to determine the number of $20 bills needed, and
then reduce the amount by the total value of the $20 bills. Repeat for the other
bill sizes.
.*/

#include<stdio.h>

int main(){

    int x;
    printf("Enter a dollar amount: \n");
    scanf("%d", &x);//input

    int bill_20 = x/20;
    int bill_10 = (x%20)/10;
    int bill_5  = (x%10)/5;
    int bill_1 = x%5;

    printf("$20 bills: %d\n", bill_20);
    printf("$10 bills: %d\n", bill_10);
    printf("$5 bills: %d\n", bill_5);
    printf("$1 bills: %d\n", bill_1);

    return 0;
}
