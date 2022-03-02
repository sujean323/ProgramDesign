#include<stdio.h>

int main(void){

    int blood=10;
    int strength=2;
    int monster;
    int play=1;//still playing the game
    int village=1;//in the village
    int choose;//what to do in the village
    int sword=1;//whether the player have brought a sword

    printf("Welcome, Adventurer!\n");//Beginning of the game




    //make sure player in the game
    while(play == 1){
        printf("Do you want to go to our village first (1:Yes; 0: No)?\n");//Ask if the player wants to go to the village.
        scanf("%d", &village);

        //choose to go to the village before selecting which monster to combat
        while(village==1){
            if(village==1){
                printf("What do you want to do in our village (1:buy a magical sword; 2: go to the bar; 3:leave the village)?\n");//Ask which actions the player want to do in the village
                scanf("%d", &choose);

                if(choose!=1 && choose!=2 && choose!=3){
                    printf("Invalid action! 1: buy a magical sword; 2: go to the bar; 3: leave the village\n");//Message if player enter action not in the range from 1 to 3
                }
                else if(choose==1){
                    if(sword==1){
                        strength++;
                        printf("Nice sword! Now you have %d strength!\n", strength);//Message after the player buys a magical sword
                        sword=0;
                    }
                    else if(sword==0){
                        printf("You already brought a sword.\n");//Message if the player already brought a sword during this visit and wants to buy another sword.
                    }
                }
                else if(choose==2){
                    if(blood<10){
                        blood++;
                        printf("Nice beer! Now you have %d blood!\n", blood);//Message after the player goes to the bar.
                    }
                    else if(blood>=10){
                        printf("Your blood is full. You don't need a beer.\n");//Message after the player goes to the bar with the blood no less than 10
                    }
                }
                else if(choose==3){
                    printf("You are welcome to come back anytime!\n");//Message after the player leaves the village
                    village=0;
                }
            }
            else if(village==0){
                village=0;
            }//After exiting the village the player will be asked to choose which monster to fight
        }
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
        village=1;
        sword=1;

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
