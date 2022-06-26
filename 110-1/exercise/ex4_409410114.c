#include<stdio.h>

int main(void){

    int blood=10;
    int strength=2;
    int monster;
    int play=1;//still playing the game

    printf("Welcome, Adventurer!\n");//Beginning of the game

//make sure player in the game
    while(play == 1){
        printf("You have %d blood and %d strength.\n", blood, strength);//Report adventurer's current status

        printf("Please choose which monster (1 to 4) you want to fight: \n");//Ask the user to choose which monster to fight
        scanf("%d", &monster);

        if(monster<1 || monster>4){
            printf("No such monster, please enter 1 to 4 to choose the monster.\n");
        }//Message when user enter the number of the monster outside the range of 1 to 4

        else if(0<monster && monster<5){
                printf("You are fighting Monster %d!\n", monster);//Report which monster is selected

                //Report the result of the combat by comparing strength between the adventurer and the monster
                if(strength>monster){
                    strength ++;
                    printf("You Win! \n");
                }
                else if(strength<=monster ){
                    blood -= monster;
                    printf("You Lose!\n");
                }
            }

        //Ask the user to decide whether to continue the game
        printf("Do you want to go on your adventure (1:Yes; 0: No) ?: \n");
        scanf("%d", &play);

        if(play==0){
            printf("We will miss you. Bye!\n");//user choose to leave the game
        }
        else if(blood<=0){
            printf("You Dead. Bye!\n");//the adventurer's blood is less or equal to zero
            play = 0;
        }
    }

    return 0;
}
