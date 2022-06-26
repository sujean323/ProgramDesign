#include<stdio.h>
#include<string.h>

void s_upper(char s[]){
    int i;
    while(s[i] != '\0'){
        if((s[i] >= 'a') && (s[i] <= 'z')){
            s[i] = s[i]-32;
        }
        i++;
    }
    printf("%s\n", s);
}
void s_lower(char s[]){
    int i;
    while(s[i] != '\0'){
        if((s[i] >= 'A') && (s[i] <= 'Z')){
            s[i] = s[i]+32;
        }
        i++;
    }
    printf("%s\n", s);
}
void s_wave(char s[]){
    int i;
    while(s[i] != '\0'){
        if(i%2==1){
            if((s[i] >= 'A') && (s[i] <= 'Z')){
                s[i] = s[i]+32;
            }
            i++;
        }
        else{
            if((s[i] >= 'a') && (s[i] <= 'z')){
                s[i] = s[i]-32;
            }
            i++;
        }
    }
    printf("%s\n", s);
}
int main(){
    int choose;
    char s[100001];

    scanf("%s", s);
    scanf("%d", &choose);
    if(choose == 1){
        s_upper(s);
    }
    else if(choose == 2){
        s_lower(s);
    }
    else if(choose == 3){
        s_wave(s);
    }

    return 0;
}
