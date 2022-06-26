/*Write a program that asks the user to enter a two-digit number,
then prints the number with its digits reversed.
Hint: Read the number using %d, then break it into two digits.
If n is an integer, then n % 10 is the last digit in n.
*/
#include <stdio.h>
int main(void){
    int number;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);
    printf("The number with its digits reversed is %d%d\n", number%10, number/10);

    return 0;
}
