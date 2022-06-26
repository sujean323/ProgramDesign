#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
    int n, input;
    char str[101] ;
    scanf("%d", &n); //option for case sensitive/insensitive
    if(n != 1 && n != 2) return 0; //invalid option
    scanf("%d ", &input); //number of the words
    char str_cut[101][101] = {'\0'};
    //enter the words
    for(int i=0; i<input; i++){
        fgets(str, sizeof(str), stdin);
        str[strlen(str)] = '\0';
        strcpy(str_cut[i], str);
    }
    //tolower
    if(n==2 && input != 1){ //case insensitive
        for(int i=0; i<input; i++){
            for(int j=0; j<strlen(str_cut); j++){
                str_cut[i][j] = tolower(str_cut[i][j]);
            }
        }
    }
    char tmp[101];
    if(input == 0){
        printf("No longest common prefix\n");
    }
    else if(input == 1){
        printf("%s\n", str_cut[0]);
    }
    else{
        //sort
        for(int i=0; i<input; i++){
            for(int j=0; j<input-1-i; j++){
                if(strlen(str_cut[j])<strlen(str_cut[j+1])){
                    strcpy(tmp, str_cut[j]);
                    strcpy(str_cut[j], str_cut[j+1]);
                    strcpy(str_cut[j+1], tmp);
                }
                else if(strlen(str_cut[j])==strlen(str_cut[j+1])){
                    if(strcmp(str_cut[j], str_cut[j+1]) > 0){
                        //swap str_cut[j] and str_cut[j+1]
                        strcpy(tmp, str_cut[j]);
                        strcpy(str_cut[j], str_cut[j+1]);
                        strcpy(str_cut[j+1], tmp);
                    }
                }
            }
        }
        //compare
        long int len = strlen(str_cut[input-1]);
        char ans[100] = {'\0'};
        long int j=0, c=0, k=0;
        while(j<len){
            for(int i=0; i<input; i++){
                if(str_cut[input-1][j] == str_cut[i][j]){
                    c++;
                    if(c==input-1){
                        ans[k] = str_cut[input-1][j];
                        k++;
                    }
                }
                else{
                    j=len+1;
                    break;
                }
            }
            j++;
            c=0;
        }
        if(strlen(ans)!=0){
            for(int i=0; i<strlen(ans); i++){
                printf("%c", ans[i]);
            }
            //printf("\n");
        }
        else{
            printf("No longest common prefix\n");
        }
    }
    return 0;
}
