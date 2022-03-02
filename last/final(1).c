#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int check_boundary(int row, int col, int map_row, int map_col){
    if(row<0 || row>map_row-1 || col<0 || col>map_col-1){
        printf("the location is outside the map\n");
        return 0;
    }
    else
        return 1;
}

int check_availability(char** map, int row, int col){
    if(map[row][col] == '.')
        return 1;
    else
    {
        printf("the location is occupied\n");
        return 0;
    }
}

void print_map(char** map, int map_row, int map_col){
    printf("=== MAP ===\n");
    for(int i=0; i<map_row; i++){
        for(int j=0; j<map_col; j++){
            printf("%c ", map[i][j]);
        }
    printf("\n");
    }
    printf("=== MAP ===\n");
}

char** create_map(char** map, int* map_row, int* map_col){
    printf("Input the number of row and column for the map: \n");
    scanf("%d%d", map_row, map_col);
    //為二維指標開空間
    map = (char **)malloc(sizeof(char *)*(*map_row));
    //為一維指標開空間
    for(int i=0; i < (*map_row); i++)
        map[i] = (char*)malloc(sizeof(char)*(*map_col));
    //set all the elements to be '.'
    for(int i=0; i < (*map_row); i++){
        for(int j=0; j < (*map_col) ; j++)
            map[i][j] = '.';
    }
    print_map(map, (*map_row), (*map_col));
    return map;
}
void setup_village(char** map, int map_row, int map_col){
    int village_row, village_col;
    while(1){
        printf("Input the row and column for the village location: \n");
        scanf("%d %d", &village_row, &village_col);

        if(check_boundary(village_row, village_col, map_row, map_col)  && check_availability(map, village_row, village_col))
        {
            map[village_row][village_col] = 'v';
            break;
        }
        else
            continue;
    }
    print_map(map, map_row, map_col);
}
void encounter_villiage(int* player_health, int* player_attack){
    int go; // decide whether go to the village or not
    int choose; // what to do in the village
    int sword=1;
    while(1){
        printf("Do you want to go to our village first (1:Yes; 0: No)?\n");//Ask if the player wants to go to the village.
        scanf("%d", &go);
        if(go == 1){
            printf("What do you want to do in our village (1:buy a magical sword; 2: go to the bar; 3:leave the village)?\n");
            scanf("%d", &choose);
            if(choose == 1){
                if(sword == 1){
                    (*player_attack)++;
                    printf("Nice sword! Now you have %d strength!\n", *player_attack);
                    sword = 0;
                }
                else if(sword == 0)
                    printf("You already brought a sword.\n");
            }
            else if(choose == 2){
                if(*player_health<10){
                    (*player_health)++;
                    printf("Nice beer! Now you have %d player_health!\n", *player_health);
                }
                else if((*player_health)>=10)
                    printf("Your player_health is full. You don't need a beer.\n");
            }
            else if(choose == 3){
                printf("You are welcome to come back anytime!\n");
                break;
            }
        }
        else
            break;
    }
}
void setup_monster(char** map, int* monster, int map_row, int map_col){
     int monster_row, monster_col;
    *monster = (map_row/10 + map_row%10);
    printf("Input the row and column for the monster location: \n");
    for(int i=0; i<*monster; i++){
        printf("Input the row and column for monster %d: \n", i);
        scanf("%d%d", &monster_row, &monster_col);
        if(check_boundary(monster_row, monster_col, map_row, map_col) != 0 && check_availability(map, monster_row, monster_col) != 0)
            map[monster_row][monster_col] = 'm';
        else
            i--;
    }
    print_map(map, map_row, map_col);
}
void battle_result(int* monster, int* player_health, int* player_attack){
    srand(time(0));
    while(1){
        int seed = rand()%101;
        printf("You have %d player_health and %d player_attack.\n", (*player_health), (*player_attack));
        if(seed>50){
            printf("dodge probability is : %d\n", seed);
            printf("monster dodge successfully\n");
            (*player_health) -= *monster;
            printf("You have %d player_health and %d player_attack.\n", (*player_health), (*player_attack));
        }
        else{
            printf("dodge probability is : %d\n", seed);
            if((*player_attack)>*monster){
                (*player_attack)++;
                printf("You Win! \n");
                printf("You have %d player_health and %d player_attack.\n", (*player_health), (*player_attack));
                break;
            }
            else{
                (*player_health) -= *monster;
                printf("You Lose!\n");
                printf("You have %d player_health and %d player_attack.\n", (*player_health), (*player_attack));
                break;
            }
        }
        encounter_monster(monster, player_health, player_attack);
    }
}
void encounter_monster(int* monster, int* player_health, int* player_attack){
    printf("Please choose which monster (1 to 4) you want to fight: \n");
    scanf("%d", monster);
    if(*monster<1 || *monster>4)
        printf("No such monster, please enter 1 to 4 to choose the monster.\n");
    else{
        printf("You are fighting monster %d!\n", *monster);
        battle_result(monster, player_health, player_attack);
    }
    if(*player_health<=0){
        printf("You Dead. Bye!\n");
        exit(0);
    }
}

void setup_player(char** map, int map_row, int map_col, int* player_row, int* player_col){
    while(1){
        printf("Input the row and column for player: \n");
        scanf("%d %d", player_row, player_col);
        if(check_boundary((*player_row), (*player_col), map_row, map_col) && check_availability(map, (*player_row), (*player_col)))
        {
            map[*player_row][*player_col] = 'p';
            break;
        }
        else
            continue;
    }
    print_map(map, map_row, map_col);
}
void setup_gun(char** map, int map_row, int map_col){
    int gun_row, gun_col;
    while(1){
        printf("Input the row and column for gun: \n");
        scanf("%d%d", &gun_row, &gun_col);
        if((check_boundary(gun_row, gun_col, map_row, map_col)) && (check_availability(map, gun_row, gun_col))){
            map[gun_row][gun_col] = 'g';
            break;
        }
    }
    print_map(map, map_row, map_col);
}
void go_up(char** map, int* monster, int* player_row, int player_col, int map_row, int map_col, int* player_health, int* player_attack){
    (*player_row)--;
    if(check_boundary((*player_row), player_col, map_row, map_col) != 0){
        if(map[*player_row][player_col] == '.'){
            map[*player_row][player_col] = 'p';
            map[(*player_row)+1][player_col] = '.';
        }
        else if(map[*player_row][player_col] == 'v'){
            encounter_villiage(player_health, player_attack);
            (*player_row)++;
        }
        else if(map[*player_row][player_col] == 'm'){
            encounter_monster(monster, player_health, player_attack);
            (*player_row)++;
        }
        else if(map[*player_row][player_col] == 'g'){
            (*player_attack)++;
            printf("You have %d player_health and %d player_attack.\n", (*player_health), (*player_attack));
            (*player_row)++;
        }
        else if(map[*player_row][player_col] == 't'){
            (*player_health)--;
            printf("You have %d player_health and %d player_attack.\n", (*player_health), (*player_attack));
            (*player_row)++;
        }
        print_map(map, map_row, map_col);
    }
    else{
        printf("You can't go there!\n");
        (*player_row)++;
    }
}
void go_down(char** map, int* monster, int* player_row, int player_col, int map_row, int map_col, int* player_health, int* player_attack){
    (*player_row)++;
    if(check_boundary((*player_row), player_col, map_row, map_col) != 0){
        if(map[*player_row][player_col] == '.'){
            map[*player_row][player_col] = 'p';
            map[(*player_row)-1][player_col] = '.';
        }
        else if(map[*player_row][player_col] == 'v'){
            encounter_villiage(player_health, player_attack);
            (*player_row)--;
        }
        else if(map[*player_row][player_col] == 'm'){
            encounter_monster(monster, player_health, player_attack);
            (*player_row)--;
        }
        else if(map[*player_row][player_col] == 'g'){
            (*player_attack)++;
            printf("You have %d player_health and %d player_attack.\n", (*player_health), (*player_attack));
            (*player_row)--;
        }
        else if(map[*player_row][player_col] == 't'){
            (*player_health)--;
            printf("You have %d player_health and %d player_attack.\n", (*player_health), (*player_attack));
            (*player_row)--;
        }
        print_map(map, map_row, map_col);
    }
    else{
        printf("You can't go there!\n");
        (*player_row)--;
    }
}
void go_right(char** map, int* monster, int player_row, int* player_col, int map_row, int map_col, int* player_health, int* player_attack){
    (*player_col)++;
    if(check_boundary(player_row, (*player_col), map_row, map_col) != 0){
        if(map[player_row][*player_col] == '.'){
            map[player_row][*player_col] = 'p';
            map[player_row][(*player_col)-1] = '.';
        }
        else if(map[player_row][*player_col] == 'v'){
            encounter_villiage(player_health, player_attack);
            (*player_col)--;
        }
        else if(map[player_row][*player_col] == 'm'){
            encounter_monster(monster, player_health, player_attack);
            (*player_col)--;
        }
        else if(map[player_row][*player_col] == 'g'){
            (*player_attack)++;
            printf("You have %d player_health and %d player_attack.\n", *player_health, *player_attack);
            (*player_col)--;
        }
        else if(map[player_row][*player_col] == 't'){
            (*player_health)--;
            printf("You have %d player_health and %d player_attack.\n", *player_health, *player_attack);
            (*player_col)--;
        }
        print_map(map, map_row, map_col);
    }
    else{
        printf("You can't go there!\n");
        (*player_col)--;
    }
}
void go_left(char** map, int* monster, int player_row, int* player_col, int map_row, int map_col, int* player_health, int* player_attack){
    (*player_col)--;
    if(check_boundary(player_row, (*player_col), map_row, map_col) != 0){
        if(map[player_row][*player_col] == '.'){
            map[player_row][*player_col] = 'p';
            map[player_row][(*player_col)+1] = '.';
        }
        else if(map[player_row][*player_col] == 'v'){
            encounter_villiage(player_health, player_attack);
            (*player_col)++;
        }
        else if(map[player_row][*player_col] == 'm'){
            encounter_monster(monster, player_health, player_attack);
            (*player_col)++;
        }
        else if(map[player_row][*player_col] == 'g'){
            (*player_attack)++;
            printf("You have %d player_health and %d player_attack.\n", *player_health, *player_attack);
            (*player_col)++;
        }
        else if(map[player_row][*player_col] == 't'){
            (*player_health)--;
            printf("You have %d player_health and %d player_attack.\n", *player_health, *player_attack);
            (*player_col)++;
        }
        print_map(map, map_row, map_col);
    }
    else{
        printf("You can't go there!\n");
        (*player_col)++;
    }
}

void setup_trap(char** map, int map_row, int map_col){
    int trap_row, trap_col;
    while(1){
        printf("Input the row and column for trap: \n");
        scanf("%d%d", &trap_row, &trap_col);
        if(check_boundary(trap_row, trap_col, map_row, map_col) != 0 && check_availability(map, trap_row, trap_col) != 0){
            map[trap_row][trap_col] = 't';
            break;
        }
    }
    print_map(map, map_row, map_col);
}

void travel_map(char** map, int* monster, int map_row, int map_col, int* player_row, int* player_col, int* player_health, int* player_attack){
    print_map(map, map_row, map_col);
    while(1){
        int choose;
        printf("[1] go up [2] go down [3] go right [4] go left [5] exit: ");
        scanf("%d", &choose);
        if(choose == 1)
            go_up(map, monster, player_row, *player_col, map_row, map_col, player_health, player_attack);
        else if(choose == 2)
            go_down(map, monster, player_row, *player_col, map_row, map_col, player_health, player_attack);
        else if(choose == 3)
            go_right(map, monster, *player_row, player_col, map_row, map_col, player_health, player_attack);
        else if(choose == 4)
            go_left(map, monster, *player_row, player_col, map_row, map_col, player_health, player_attack);
        else if(choose == 5)
            exit(0);
    }
}
void start_game(){
    char** map = NULL;
    printf("Welcome, Adventurer!\n");
    while(1){
        int map_row, map_col, player_row, player_col, monster;
        int player_health = 10;
        int player_attack = 2;
        int choose;
        printf("[1] Create a new map [2] Start travel the map: ");
        scanf("%d", &choose);
        if(choose == 1){
            map = create_map(map, &map_row, &map_col);
            setup_village(map, map_row, map_col);
            setup_monster(map, &monster, map_row, map_col);
            setup_player(map, map_row, map_col, &player_row, &player_col);
            setup_gun(map, map_row, map_col);
            setup_trap(map, map_row, map_col);
        }
        else if(choose == 2){
            travel_map(map, &monster, map_row, map_col, &player_row, &player_col, &player_health, &player_attack);
        }
    }
}

int main(){
    start_game();
    return 0;
}



