#include<stdio.h>
#define MAX_ROW 1000
#define MAX_COL 1000

// declare global variable
char maps[MAX_ROW][MAX_COL]; //global map.
int num_row,num_col; //number of map's row and column.
int player_row,player_col; // player's row and column.
// declare function
void init_game(); // initial maps,village,monster.
void create_map(); // create num_row x num_col size maps.
void print_map(); // output map.
void setup_village(); // set village location.
void setup_monster(); // set monster location.
void setup_player(); // set player location.
int check_boundary(int set_row,int set_col); // check it is outside or not.
int check_availability(int set_row,int set_col); // check there exists obstacle or not.
int check_move(int move_row,int move_col); // check player can move or not.
void go_up(); // just go up.
void go_down(); // just go down.
void go_right(); // just go right.
void go_left(); // just go left.
void travel_maps(); // travel maps.
void start_game();  //start game.

// function code
int main()
{
    start_game();
    return 0;
}
void init_game()
{
    create_map();
    setup_village();
    setup_monster();
}
void create_map()
{
    for(int i=0;i<MAX_ROW;i++)
        for(int j=0;j<MAX_COL;j++)
            maps[i][j] = '.';
    printf("Input the number of row and column for the map:\n");
    scanf("%d %d",&num_row,&num_col);
    return;
}
void print_map()
{
    printf("=== MAP ===\n");
    for(int i=0;i<num_row;i++)
    {
        for(int j=0;j<num_col;j++)
        {
            printf("%c ",maps[i][j]);
        }
        printf("\n");
    }
    printf("=== MAP ===\n");
    return;
}
void setup_village()
{
    while(1)
    {
        int village_row,village_col;
        printf("Input the row and column for the village location: \n");
        scanf("%d %d",&village_row,&village_col);
        if(check_boundary(village_row,village_col) == 0)
            continue;
        else if(check_availability(village_row,village_col) == 0)
            continue;
        maps[village_row][village_col] = 'v';
        break;
    }
}
void setup_monster()
{
    int number_monster; // number of monster
    number_monster = (num_row/10)+(num_row%10);
    printf("You need to assign location for %d monsters in total\n",number_monster);
    for(int i=0;i<number_monster;)
    {
        printf("Input the row and column for monster %d:\n",i);
        int monster_setrow,monster_setcol;
        scanf("%d %d",&monster_setrow,&monster_setcol);
        if(check_boundary(monster_setrow,monster_setcol) == 0)
            continue;
        else if(check_availability(monster_setrow,monster_setcol) == 0)
            continue;
        maps[monster_setrow][monster_setcol] = 'm';
        i++;
    }
}
void setup_player()
{
    while(1){
        printf("Input the row and column for player:\n");
        scanf("%d %d",&player_row,&player_col);
        if(check_boundary(player_row,player_col) == 0)
            continue;
        else if(check_availability(player_row,player_col) == 0)
            continue;
        maps[player_row][player_col] = 'p';
        break;
    }
}
int check_boundary(int set_row,int set_col)
{
    if(set_row < 0 || set_row >= num_row || set_col < 0 || set_col >= num_col)
    {
        printf("the location is outside the map\n");
        return 0;
    }
    return 1;

}
int check_availability(int set_row,int set_col)
{
    if(maps[set_row][set_col] != '.')
    {
        printf("the location is occupied\n");
        return 0;
    }
    return 1;
}
int check_move(int move_row,int move_col)
{
    int flag = 1;
    if(move_row < 0 || move_row >= num_row){
        flag = 0;
    }
    else if(move_col < 0 || move_col >= num_col){
        flag = 0;
    }
    else if(maps[move_row][move_col] != '.'){
        flag = 0;
    }
    if(flag == 0)
    {
        printf("you can't go there\n");
        return 0;
    }
    return 1;
}
void go_up()
{
    if(check_move(player_row-1,player_col) == 0)
        return;
    maps[player_row][player_col] = '.';
    player_row-=1;
    maps[player_row][player_col] = 'p';
	print_map();
    return;
}
void go_down()
{
    if(check_move(player_row+1,player_col) == 0)
        return;
    maps[player_row][player_col] = '.';
    player_row+=1;
    maps[player_row][player_col] = 'p';
	print_map();
    return;
}
void go_right()
{
    if(check_move(player_row,player_col+1) == 0)
        return;
    maps[player_row][player_col] = '.';
    player_col+=1;
    maps[player_row][player_col] = 'p';
	print_map();
    return;
}
void go_left()
{
    if(check_move(player_row,player_col-1) == 0)
        return;
    maps[player_row][player_col] = '.';
    player_col-=1;
    maps[player_row][player_col] = 'p';
	print_map();
    return;
}
void travel_maps()
{
    setup_player();
    print_map();
    while(1)
    {
        int choose;
        printf("[1] go up [2] go down [3] go right [4] go left [5] exit: ");
        scanf("%d",&choose);
        if(choose == 1){
            go_up();
        }
        else if(choose == 2){
            go_down();
        }
        else if(choose == 3){
            go_right();
        }
        else if(choose == 4){
            go_left();
        }
        else if(choose == 5){
            return;
        }
    }
    return;
}
void start_game()
{
    init_game();
    while(1)
    {
		print_map();
        int choose;
        printf("[1] Create a new map [2] Start travel the map: ");
        scanf("%d",&choose);
        if(choose == 1){
            init_game();
        }
        else if(choose == 2){
            travel_maps();
            return;
        }
    }
}
