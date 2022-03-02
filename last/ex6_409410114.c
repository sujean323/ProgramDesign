#include<stdio.h>

int main(){
    int row, col, rowv, colv, rowm, colm;

    printf("Input the number of row and column for the map: \n");
    scanf("%d%d", &row, &col);

    char arr[row][col];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr[i][j] = '.';
        }
    }

    int inside=1;
    while(inside==1){
        printf("Input the row and column for the village location: \n");
        scanf("%d%d", &rowv, &colv);

        if(rowv>row-1 || colv>col-1 || rowv<0 ||colv<0){
            printf("the location is outside the map\n");//when the location input by users is outside the range of the array
        }
        else if(rowv<row && colv<col){
            arr[rowv][colv] = 'v';
            inside = 0;
        }
    }

    int monster = (row/10) + (row%10);
    printf("You need to assign location for %d monsters in total\n", monster);

    while(inside==0){
        for(int i=0; i<monster; ){
            printf("Input the row and column for monster %d: \n", i);
            scanf("%d%d", &rowm, &colm);

            if(rowm>row-1 || colm>col-1 || rowm<0 ||colm<0){
                printf("the location is outside the map\n");//when the location input by users is outside the range of the array
            }
            else if('v' == arr[rowm][colm]){
                printf("the location is occupied\n");//the location is already taken by the village or other monsters
            }
            else if(rowm<row && colm<col){
                arr[rowm][colm] = 'm';
                inside = 1;
                i++;
            }
        }
    }

    printf("=== MAP ===\n");
    for(int j=0; j<row; j++){
        for(int k=0; k<col; k++){
            printf("%c ", arr[j][k]);
        }
    printf("\n");
    }
    printf("=== MAP ===\n");

    return 0;
}
