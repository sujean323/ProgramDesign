#define _GNU_SOURCE //strcasestr
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//insensitive strstr()
extern char *strcasestr(const char *, const char *);
/*
char *stristr( const char* str1, const char* str2 ){
    const char* p1 = str1 ;
    const char* p2 = str2 ;
    const char* r = *p2 == 0 ? str1 : 0 ;

    while( *p1 != 0 && *p2 != 0 ){
        if( tolower( (unsigned char)*p1 ) == tolower( (unsigned char)*p2 ) ){
            if( r == 0 ){
                r = p1 ;
            }
            p2++ ;
        }
        else{
            p2 = str2 ;
            if( r != 0 ){
                p1 = r + 1 ;
            }
            if( tolower( (unsigned char)*p1 ) == tolower( (unsigned char)*p2 ) ){
                r = p1 ;
                p2++ ;
            }
            else{
                r = 0 ;
            }
        }
        p1++ ;
    }
    return *p2 == 0 ? (char*)r : 0 ;
}
*/
//replace the word in the article
char *strrpc(char *str2, char *cut0, char *cut1){
    int len = strlen(str2)-strlen(cut0)+strlen(cut1)+1;
    char output[len];
    int flag=0;
    //initial
    for(int i=0; i<len; i++){
        output[i] = '\0';
    }
    for(int i=0; i<strlen(str2); i++){
       if(strncasecmp(str2+i, cut0, strlen(cut0)) == 0&&flag == 0){ //same string length
            strcat(output, cut1);
            i += strlen(cut0)-1;
            flag++;
        }
        else{ //different string length
            strncat(output,str2+i, 1);
        }
    }
    strcpy(str2, output);
    return str2;
}
//if there is dash in input
int dash(char t){
    if(t == '-'){
        return 1;
    }
    else return 0;
}

int main() {
    char str1[101], str2[4096];
    char str1_cut[4][100] = {'\0'};
    char d[] = " ,./ \\?!@#<>=+][{}$^_';|:\"&~\t\n\r`%*()"; //symbols can't be put in the word
    char *p;
    char *ret;
    int i = 0;
    //initial
    for(int i=0; i<3; i++){
        for(int j=0; j<100; j++){
            str1_cut[i][j] = '\0';
        }
    }
    //Enter pattern, replacement, and at most one parameter
    fgets(str1, sizeof(str1), stdin);
    //remove line break
    str1[strlen(str1)-1] = '\0';
    //string segmentation
    p = strtok(str1, " \t\n");
    while (p != NULL){
        for(int j=0; j<strlen(p); j++){
            str1_cut[i][j] = p[j];
        }
        i++;
        if(i>3) break; //the word of input are more than three
        p = strtok(NULL, " \t\n\r");
    }
    //the parameter isn't "-i" or input other words after parameter
    if(((strcmp(str1_cut[2], "-i") != 0) && strlen(str1_cut[2]) != 0) || strlen(str1_cut[3]) != 0){
        printf("The input format: string1 string2 [parameter]\n");
        return 0;
    }
    //string1 is incorrect
    for(int j=0; j<strlen(str1); j++){
         if(isalnum(str1[j]) == 0 && dash(str1[j]) == 0){
            printf("The input format: string1 string2 [parameter]\n");
            return 0;
         }
    }
    //Enter the article
    while(fgets(str2, sizeof(str2), stdin) != NULL){
        //remove line break
        str2[strlen(str2)-1] = '\0';
        //string segmentation
        p = strtok(str2, d);
        while (p != NULL){
            //avoid pointer p be changed
            char t[4096]={'\0'};
            strcpy(t, p);
            //parameter is -i
            if(strcmp(str1_cut[2], "-i") == 0){
                ret = strcasestr(t, str1_cut[0]);
            }
            //no parameter
            else if(strlen(str1_cut[2]) == 0){
                ret = strstr(t, str1_cut[0]);
            }
            if(ret != NULL){
                printf("%s\n", strrpc(t, str1_cut[0], str1_cut[1]));
            }
            p = strtok(NULL, d);
        }
    }

    return 0;
}
