/*
Write a program that asks the user to enter a dollars-and-cents amount,
then display the amount of 5% tax added.
Only two digits are allowed after the decimal point for the output.
*/

#include<stdio.h>

int main(void){
    float amount;

    printf("Enter an amount: ");
    scanf("%f", &amount);
    printf("amount of tax added: $%.2f\n", amount *1.05);
    //The %.2f is a format specifier and is something very different.
    //The 1.05f does denote a floating point number with value approximately 1.05
    return 0;
}
