#include<stdio.h>

int main(){
    int day;//the number of days in a month
    int week;//the starting day of the week
    int i;//count day
    int j;//count week

    printf("Enter the number of days in a month and the starting day of the week: \n");
    scanf("%d%d", &day, &week);

    //the blank days of the first week
    for(i = 1; i < week; i++){
        printf("   ");
    }

    for(j = 1; j <= day; i++, j++){
        printf("%3d", j);//%3d represent at least 3 digits align right
        if(i%7 == 0){
            printf("\n");
        }
    }

    printf("\n\n");

    return 0;
}
