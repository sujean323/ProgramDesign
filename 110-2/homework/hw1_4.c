#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
    char str[100000], word[50];
    int i, j, tmp, ans=0, c, flag;
    //input
    fgets(str, sizeof(str), stdin);
    fgets(word, sizeof(word), stdin);
    //remove "\n" and "\r"
    for(int k=0; k<strlen(str); k++){
        if(str[k] == '\r' || str[k] == '\n'){
            str[k] = '\0';
        }
    }
    for(int k=0; k<strlen(str); k++){
        if(word[k] == '\r' || word[k] == '\n'){
            word[k] = '\0';
        }
    }
    //character-by-character matching
    for(i=0; i<strlen(str); i++){
        tmp = i;
        flag=0;
        for(j=0; j<strlen(word); j++){
            if(str[i]==word[j]){
                //solve the problem like input 1.bebe 2.be
                if(tmp>0 && (tmp+strlen(word)<strlen(str))){
                    if(str[tmp-1] == ' ' && str[tmp+strlen(word)] == ' '){
                        flag=1;
                    }
                }
                else if(tmp==0 && tmp+strlen(word)<strlen(str)){
                    if(str[tmp+strlen(word)] == ' '){
                        flag=1;
                    }
                }
                else if(tmp>0 && (tmp+strlen(word))==strlen(str)){
                    if(str[tmp-1] == ' '){
                        flag=1;
                    }
                }
                if(flag==1) i++;
                else break;
            }
        }
        c = i-tmp;
        if(c==strlen(word)){
            ans++;
        }
        i = tmp;
    }
   printf("%d", ans);

    return 0;
}
