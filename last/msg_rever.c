#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    char a[100];
    char ch;
    int count=0;
    char *ptr = a;

    //Ū�J�r��
    while(count<100){
        ch = getchar();
        count++;
        *ptr++ = ch;
        if(ch == '\n')
            break;
    }
    //*ptr = '\0';
    //ptr--;
    //�L�X�r��
    while(1){
        printf("%c", *ptr);
        //�̫�@���L��a[0]�ɸ��X�j��
        if(ptr == a){
            printf("%c", *ptr);
            break;
        }
        *ptr--;
    }

    return 0;
}
