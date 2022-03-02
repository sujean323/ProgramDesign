#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int map_row, map_col, village_row, village_col, monster_row, monster_col, player_row, player_col, gun_row, gun_col, trap_row, trap_col;
int monster; // choose a monster to fight
int player_health =10;
int player_attack = 2;
char map[1000][1000];

int main(){
    printf("Welcome, Adventurer!\n");
    init_game();
    return 0;
}
void create_map(){
    printf("Input the number of row and column for the map: \n");
    scanf("%d%d", &map_row, &map_col);
    //set all the elements to be '.'
    for(int i=0; i<map_row; i++){
        for(int j=0; j<map_col ; j++)
            map[i][j] = '.';
    }
    print_map();
}
void print_map(){
    printf("=== MAP ===\n");
    for(int j=0; j<map_row; j++){
        for(int k=0; k<map_col; k++){
            printf("%c ", map[j][k]);
        }
    printf("\n");
    }
    printf("=== MAP ===\n");
}
void setup_village(){
    while(1){
        printf("Input the row and column for the village location: \n");
        scanf("%d%d", &village_row, &village_col);
        if(check_boundary(village_row, village_col) != 0 && check_availability(village_row, village_col) != 0){
            map[village_row][village_col] = 'v';
            break;
        }
    }
    print_map(map_row, map_col);
}
void encounter_villiage(){
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
                    player_attack++;
                    printf("Nice sword! Now you have %d strength!\n", player_attack);
                    sword = 0;
                }
                else if(sword == 0)
                    printf("You already brought a sword.\n");
            }
            else if(choose == 2){
                if(player_health<10){
                    player_health++;
                    printf("Nice beer! Now you have %d player_health!\n", player_health);
                }
                else if(player_health>=10)
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
void setup_monster(){
    int monster = (map_row/10) + (map_row%10);
    printf("Input the row and column for the monster location: \n");
    for(int i=0; i<monster; i++){
        printf("Input the row and column for monster %d: \n", i);
        scanf("%d%d", &monster_row, &monster_col);
        if(check_boundary(monster_row, monster_col) != 0 && check_availability(monster_row, monster_col) != 0)
            map[monster_row][monster_col] = 'm';
        else
            i--;
    }
    print_map();
}
void encounter_monster(){
    printf("Please choose which monster (1 to 4) you want to fight: \n");
    scanf("%d", &monster);
    if(monster<1 || monster>4)
        printf("No such monster, please enter 1 to 4 to choose the monster.\n");
    else{
        printf("You are fighting monster %d!\n", monster);
        battle_result();
    }
    if(player_health<=0){
    printf("You Dead. Bye!\n");
    exit(0);
    }
}
void battle_result(){
    srand(time(0));
    int seed;
    while(1){
        seed = rand()%101;
        if(seed>50){
            printf("dodge probability is : %d\n", seed);
            printf("monster dodge successfully\n");
        }
        else{
            printf("dodge probability is : %d\n", seed);
            if(player_attack>monster){
                player_attack++;
                printf("You Win! \n");
                break;
            }
            else{
                player_health -= monster;
                printf("You Lose!\n");
                break;
            }
        }
        printf("Please choose which monster (1 to 4) you want to fight: \n");
        scanf("%d", &monster);
    }
}
void setup_player(){
    while(1){
        printf("Input the row and column for player: \n");
        scanf("%d%d", &player_row, &player_col);
        if(check_boundary(player_row, player_col) != 0 && check_availability(player_row, player_col) != 0){
            map[player_row][player_col] = 'p';
            break;
        }
    }
    print_map();
}
void go_up(){
    player_row--;
    if(check_boundary(player_row, player_col) != 0){
        if(map[player_row][player_col] == '.'){
            map[player_row][player_col] = 'p';
            map[player_row+1][player_col] = '.';
        }
        else if(map[player_row][player_col] == 'v'){
            encounter_villiage();
            player_row++;
        }
        else if(map[player_row][player_col] == 'm'){
            encounter_monster();
            player_row++;
        }
        else if(map[player_row][player_col] == 'g'){
            player_attack++;
            printf("You have %d player_health and %d player_attack.\n", player_health, player_attack);
            player_row++;
        }
        else if(map[player_row][player_col] == 't'){
            player_health--;
            printf("You have %d player_health and %d player_attack.\n", player_health, player_attack);
            player_row++;
        }
        print_map();
    }
    else{
        printf("You can't go there!\n");
        player_row++;
    }
}
void go_down(){
    player_row++;
    if(check_boundary(player_row, player_col) != 0){
        if(map[player_row][player_col] == '.'){
            map[player_row][player_col] = 'p';
            map[player_row-1][player_col] = '.';
        }
        else if(map[player_row][player_col] == 'v'){
            encounter_villiage();
            player_row--;
        }
        else if(map[player_row][player_col] == 'm'){
            encounter_monster();
            player_row--;
        }
        else if(map[player_row][player_col] == 'g'){
            player_attack++;
            printf("You have %d player_health and %d player_attack.\n", player_health, player_attack);
            player_row--;
        }
        else if(map[player_row][player_col] == 't'){
            player_health--;
            printf("You have %d player_health and %d player_attack.\n", player_health, player_attack);
            player_row--;
        }
        print_map();
    }
    else{
        printf("You can't go there!\n");
        player_row--;
    }
}
void go_right(){
    player_col++;
    if(check_boundary(player_row, player_col) != 0){
        if(map[player_row][player_col] == '.'){
            map[player_row][player_col] = 'p';
            map[player_row][player_col-1] = '.';
        }
        else if(map[player_row][player_col] == 'v'){
            encounter_villiage();
            player_col--;
        }
        else if(map[player_row][player_col] == 'm'){
            encounter_monster();
            player_col--;
        }
        else if(map[player_row][player_col] == 'g'){
            player_attack++;
            printf("You have %d player_health and %d player_attack.\n", player_health, player_attack);
            player_col--;
        }
        else if(map[player_row][player_col] == 't'){
            player_health--;
            printf("You have %d player_health and %d player_attack.\n", player_health, player_attack);
            player_col--;
        }
        print_map();
    }
    else{
        printf("You can't go there!\n");
        player_col--;
    }
}
void go_left(){
    player_col--;
    if(check_boundary(player_row, player_col) != 0){
        if(map[player_row][player_col] == '.'){
            map[player_row][player_col] = 'p';
            map[player_row][player_col+1] = '.';
        }
        else if(map[player_row][player_col] == 'v'){
            encounter_villiage();
            player_col++;
        }
        else if(map[player_row][player_col] == 'm'){
            encounter_monster();
            player_col++;
        }
        else if(map[player_row][player_col] == 'g'){
            player_attack++;
            printf("You have %d player_health and %d player_attack.\n", player_health, player_attack);
            player_col++;
        }
        else if(map[player_row][player_col] == 't'){
            player_health--;
            printf("You have %d player_health and %d player_attack.\n", player_health, player_attack);
            player_col++;
        }
        print_map();
    }
    else{
        printf("You can't go there!\n");
        player_col++;
    }
}
void setup_gun(){
    while(1){
        printf("Input the row and column for gun: \n");
        scanf("%d%d", &gun_row, &gun_col);
        if(check_boundary(gun_row, gun_col) != 0 && check_availability(gun_row, gun_col) != 0){
            map[gun_row][gun_col] = 'g';
            break;
        }
    }
    print_map();
}
void setup_trap(){
    while(1){
        printf("Input the row and column for trap: \n");
        scanf("%d%d", &trap_row, &trap_col);
        if(check_boundary(trap_row, trap_col) != 0 && check_availability(trap_row, trap_col) != 0){
            map[trap_row][trap_col] = 't';
            break;
        }
    }
}
int check_boundary(int row, int col){
    if(row<0 || row>map_row-1 || col<0 || col>map_col-1){
        printf("the location is outside the map\n");
        return 0;
    }
    else if(row<map_row && col<map_col)
        return 1;
}
int check_availability(int row, int col){
    if(map[row][col] == '.')
        return 1;
    else{
        printf("the location is occupied\n");
        return 0;
    }
}
void travel_map(){
    print_map();
    while(1){
        int choose;
        printf("[1] go up [2] go down [3] go right [4] go left [5] exit: ");
        scanf("%d", &choose);
        if(choose == 1)
            go_up();
        else if(choose == 2)
            go_down();
        else if(choose == 3)
            go_right();
        else if(choose == 4)
            go_left();
        else if(choose == 5)
            exit(0);
    }
}
void init_game(){
    while(1){
        int choose;
        printf("[1] Create a new map [2] Start travel the map: ");
        scanf("%d", &choose);
        if(choose == 1){
            create_map();
            setup_village();
            setup_monster();
        }
        else if(choose == 2){
            setup_player();
            setup_gun();
            setup_trap();
            travel_map();
        }
    }
}
