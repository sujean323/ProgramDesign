#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//declare function
void print_board(char arr[3][3]);
int x_row(int x);
int x_col(int x);
int check_move(int x, char arr[3][3]);
void player_move(char arr[3][3]);
void AI_move(char arr[3][3]);
int check_winner(char arr[3][3]);
void print_winner(int winner);

//function code
int main(){
    char arr[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int count;
    print_board(arr);

    while(1){
        player_move(arr);
        count++;
        print_board(arr);
        if(check_winner(arr) == 1){
            print_winner(1);
            break;
        }
        else if(count==5){
            break;
        }
        AI_move(arr);
        print_board(arr);
        if(check_winner(arr) == 1){
            print_winner(2);
            break;
        }
    }
    return 0;
}
void print_board(char arr[3][3]){
    for(int i=0; i<3; i++){
        printf("%c | %c | %c\n", arr[i][0], arr[i][1], arr[i][2]);
        if(i<2){
            printf("__ ___ __\n");
        }
    }
    return;
}
int x_row(int x){
    int row ;
    if(x==1 || x==2 || x==3){
        row = 0;
    }
    else if(x==4 || x==5 ||x==6){
        row = 1;
    }
    else if(x==7 || x==8 |x==9){
        row = 2;
    }
    return row;
}
int x_col(int x){
    int col;
    if(x%3 == 0){
        col = 2;
    }
    else if(x%3 == 1){
        col = 0;
    }
    else if(x%3 == 2){
        col = 1;
    }
    return col;
}
int check_move(int x, char arr[3][3]){
    int row = x_row(x);
    int col = x_col(x);
    if(arr[row][col] == 'O' || arr[row][col] == 'X'){
        return 0;
    }
    return 1;
}
void player_move(char arr[3][3]){
    while(1){
        int x;//1~9
        printf("player-1 -> ");
        scanf("%d", &x);
        if(check_move(x, arr) == 0){
            continue;
        }
        int row = x_row(x);
        int col = x_col(x);
        arr[row][col] = 'X';
        break;
    }
}
void AI_move(char arr[3][3]){
    srand(time(0));
    int x;
    while(1){
        int x;//1~9
        x = (rand()%9)+1;
        if(check_move(x, arr) == 0){
            continue;
        }
        printf("player-2 -> %d\n", x);
        int row = x_row(x);
        int col = x_col(x);
        arr[row][col] = 'O';
        break;
    }
}
int check_winner(char arr[3][3]){
   //check horizontal line
   for(int i=0; i<3; i++){
        if(arr[i][0] == arr[i][1] && arr[i][0]== arr[i][2]){
            return 1;
        }
        else if(arr[0][i] == arr[1][i] && arr[0][i]== arr[2][i]){
            return 1;
        }

   }
    if(arr[0][0] == arr[1][1] && arr[0][0]== arr[2][2]){
        return 1;
    }
    else if(arr[0][2] == arr[1][1] && arr[0][2]== arr[2][0]){
        return 1;
    }
    return 0;
}
void print_winner(int winner){
    if(winner ==1){
        printf("player-1 wins");
    }
    else if(winner == 2){
        printf("player-2 wins");
    }
}

