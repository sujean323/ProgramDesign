/* Write a program that asks the user for a 24-hour time,
then displays the time in 12-hour form with labels of AM or PM.
The program can also identify the invalid input of time.
*/

#include<stdio.h>

int main(){
    int hour, minute;

    printf("Enter a 24-hour time: \n");//input
    scanf("%d:%d", &hour, &minute);

    if(hour<0||minute<0||hour>24||minute>59){
        printf("Incorrect Input");
    }
    //user is allowed to enter time only positive. Hour must smaller than 24. Minute must smaller than 59.
    else if(hour==0){
        printf("%d:%.2d AM", hour+12, minute);
    }
    //ensure hour 0 to be 12.
    else if(hour>12){
        printf("%d:%.2d PM", hour-12, minute);
    }
    else if(hour<12){
        printf("%d:%.2d AM", hour, minute);
    }

    return 0;
}
