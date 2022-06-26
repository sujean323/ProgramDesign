#include<stdio.h>
#include<stdlib.h>

//row col : size of array, rowv colv : location of village, rowm colm : location of monster, rowp colp : location of player
int row, col, rowv, colv, rowm, colm, rowp, colp;
char arr[1000][1000];

//Create a map for the adventure game by using the 2-dimensional array and asking users to input the size of the row and column of the array
void create_map(){
    printf("Input the number of row and column for the map: \n");
    scanf("%d%d", &row, &col);
    //set all the elements to be '.'
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr[i][j] = '.';
        }
    }
}

/*Print the 2-dimensional array for the map.
The program needs to use v to label the location of the village,
m to label the location of monsters,
 . to label the rest locations,
 and p to label the location of the player.*/

void print_map(){
    printf("=== MAP ===\n");
    for(int j=0; j<row; j++){
        for(int k=0; k<col; k++){
            printf("%c ", arr[j][k]);
        }
        printf("\n");
    }
    printf("=== MAP ===\n");
}

//Assign the index of row and column for the locations of the village. There is only one village on the map.
void setup_village(){
    while(1){
        printf("Input the row and column for the village location: \n");
        scanf("%d%d", &rowv, &colv);
        if(check_boundary(rowv, colv)){
            arr[rowv][colv] = 'v';
            break;
        }
    }
}

/*Assign the index of row and column for the locations of the monsters.
There are (row/10) + (row % 10) numbers of monsters on the map.*/
void setup_monster(){
    int monster = (row/10) + (row%10);
    printf("You need to assign location for %d monsters in total\n", monster);
    for(int i=0; i<monster; i++){
        printf("Input the row and column for monster %d: \n", i);
        scanf("%d%d", &rowm, &colm);

        if(check_boundary(rowm, colm)){// inside the map then judge whether it is occupied or not
            if(check_availability(rowm, colm)){ // is not occupied
                arr[rowm][colm] = 'm';
            }
            else // is occupried
                i--;
        }
        else // outside the map
            i--;
    }
}

/*Show a warning messag ¡§the location is outside the map¡¨
when the location of the village or monsters is outside the range of the array.*/
int check_boundary(int a, int b){
    if(a>row-1 || b>col-1 || a<0 ||b<0){
        printf("the location is outside the map\n");
        return 0;
    }
    else{
        return 1;
    }
}

int check_boundary_p(int a, int b){
    if(a>row-1 || b>col-1 || a<0 ||b<0){
        return 0;
    }
    else{
        return 1;
    }
}

/*Check whether the location is already occupied by the village or other monsters.
If the location is already taken by the village or other monsters,
the program needs to show a warning message ¡§the location is occupied¡¨*/
int check_availability(int a, int b){
        if(arr[a][b]!='.'){
            printf("the location is occupied\n");//the location is already taken by the village or other monsters
            return 0;
        }
        else{
            return 1;
        }
}

int check_availability_p(int a, int b){
        if(arr[a][b]!='.'){
            return 0;
        }
        else{
            return 1;
        }
}

/*Assign the index of row and column for the initial locations of the player.
There is only one player on the map.*/
void setup_player(int inside){
    while(inside==1){
        printf("Input the row and column for player: \n");
        scanf("%d%d", &rowp, &colp);

        if(check_boundary(rowp, colp)){
            if(check_availability(rowp, colp)){
                arr[rowp][colp] = 'p';
                break;
            }
        }
    }
}

//Move the location of the player up
void go_up(){
    arr[rowp][colp] = 'p';
    arr[rowp+1][colp] = '.';
}

//Move the location of the player down
void go_down(){
    arr[rowp][colp] = 'p';
    arr[rowp-1][colp] = '.';
}

//Move the location of the player left
void go_left(){
    arr[rowp][colp] = 'p';
    arr[rowp][colp+1] = '.';
}

//Move the location of the player right
void go_right(){
    arr[rowp][colp] = 'p';
    arr[rowp][colp-1] = '.';
}

/*If the player wants to move to the locations that are outside the map or already occupied by monsters or the village,
the program needs to show a warning message ¡§you can¡¦t go there¡¨*/
int check_move(){
    if(check_boundary_p(rowp,colp)){//inside the map then judge whether it is occupied or not
        if(check_availability_p(rowp, colp)){ // is not occupied
            return 1;
        }
        else{ // is occupried
            printf("you can't go there\n");
            return 0;
        }
    }
    else{ // outside the map
        printf("you can't go there\n");
        return 0;
    }
}

int main(){
    int choose;//Create a new map or Start travel the map
    int go;//up, down, left, right

    create_map();
    setup_village();
    setup_monster();
    print_map();

    while(1){
        printf("[1] Create a new map [2] Start travel the map: ");
        scanf("%d", &choose);

        if(choose==1){
            create_map();
            setup_village();
            setup_monster();
            print_map();
        }
        else if(choose==2){
            setup_player(1);
            print_map();

            while(1){
                printf("[1] go up [2] go down [3] go right [4] go left [5] exit: ");
                scanf("%d", &go);
                //transfer row/col to rowp/colp if player doesn't move then transfer back
                switch(go){
                    case 1:
                        rowp--;
                        if(check_move()){
                            go_up();
                            print_map();
                        }
                        else{
                            rowp++;
                        }
                        break;
                    case 2:
                        rowp++;
                        if(check_move()){
                            go_down();
                            print_map();
                        }
                        else{
                            rowp--;
                        }
                        break;
                    case 3:
                        colp++;
                        if(check_move()){
                            go_right();
                            print_map();
                        }
                        else{
                            colp--;
                        }
                        break;
                    case 4:
                        colp--;
                        if(check_move()){
                            go_left();
                            print_map();
                        }
                        else{
                            colp++;
                        }
                        break;
                    case 5:
                        exit(0);
                }
            }
        }
    }
    return 0;
}
