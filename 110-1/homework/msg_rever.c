#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    char a[100];
    char ch;
    int count=0;
    char *ptr = a;

    //讀入字串
    while(count<100){
        ch = getchar();
        count++;
        *ptr++ = ch;
        if(ch == '\n')
            break;
    }
    //*ptr = '\0';
    //ptr--;
    //印出字串
    while(1){
        printf("%c", *ptr);
        //最後一次印到a[0]時跳出迴圈
        if(ptr == a){
            printf("%c", *ptr);
            break;
        }
        *ptr--;
    }

    return 0;
}
