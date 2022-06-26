#define _GNU_SOURCE //strcasestr
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define null(n) (n == NULL)
#define dash(n) (n != '-')
#define zero(n) (n == 0)
#define d " ,./ \\?!@#<>=+][{}$^_';|:\"&~\t\n\r`%*()"
#define DEBUG 1
#define str(a, b) \
    if(a==0){\
        ret = strcasestr(t, str1_cut[0]);\
    }\
    else if(b==0){\
        ret = strstr(t, str1_cut[0]);\
    }\

//insensitive strstr()
extern char *strcasestr(const char *, const char *);
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
       if(zero(strncasecmp(str2+i, cut0, strlen(cut0))) && zero(flag)){
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
int main() {
    char str1[101], str2[4096];
    char str1_cut[4][100] = {'\0'};
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
    while (!null(p)){
        for(int j=0; j<strlen(p); j++){
            str1_cut[i][j] = p[j];
        }
        i++;
        if(i>3) break; //the word of input are more than three
        p = strtok(NULL, " \t\n\r");
    }
    //the parameter isn't "-i" or input other words after parameter or only input string1
    if(((!zero(strcmp(str1_cut[2], "-i"))) && !zero(strlen(str1_cut[2]))) || !zero(strlen(str1_cut[3])) || zero(strlen(str1_cut[1]))){
        printf("The input format: string1 string2 [parameter]\n");
        return 0;
    }
    //string1 is incorrect
    for(int j=0; j<strlen(str1); j++){
        if(zero(isalnum(str1[j])) && dash(str1[j])){
        //if(isalnum(str1[j]) == 0 && dash(str1[j])){
            printf("The input format: string1 string2 [parameter]\n");
            return 0;
         }
    }
    #if DEBUG
    if(!zero(strcmp(str1_cut[2], "-i"))){
        printf("this is case 0\n");
    }
    else{
        printf("this is case 1\n");
    }
    #endif // DEBUG
    //Enter the article
    while(!null(fgets(str2, sizeof(str2), stdin))){
        //remove line break
        str2[strlen(str2)-1] = '\0';
        //string segmentation
        p = strtok(str2, d);
        while (!null(p)){
            //avoid pointer p be changed
            char t[4096]={'\0'};
            strcpy(t, p);
            int a = strcmp(str1_cut[2], "-i");
            int b = strlen(str1_cut[2]);
            str(a,b);
            #if DEBUG
            printf("the word is: %s\n", p);
            #endif // DEBUG
            if(!null(ret)){
                printf("%s\n", strrpc(t, str1_cut[0], str1_cut[1]));
            }
            p = strtok(NULL, d);
        }
    }

    return 0;
}
