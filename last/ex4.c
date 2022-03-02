#include<stdio.h>

int main(void){

    int blood=10;
    int strength=2;
    int monster;
    int play=1;//still playing the game

    pirntf("Welcome, Adventurer!\n");

    while(play == 1){
        printf("You have %d blood and %d strength.\n");

        printf("Please choose which monster (1 to 4) you want to fight: \n");
        scanf("%d", &monster);

        if(0<monster && monster<5){
            printf("No such monster, please enter 1 to 4 to choose the monster.\n");
        }
        else if(monster<1 || monster>4){
            printf("You are fighting Monster %d!\n");
        }

        printf("You Win! \n");

        printf("You Lose!\n");

        printf("Do you want to go on your adventure (1:Yes; 0: No) ?: \n");
        scanf("%d", );

        printf("We will miss you. Bye!\n");

        printf("You Dead. Bye!\n");
    }
}
