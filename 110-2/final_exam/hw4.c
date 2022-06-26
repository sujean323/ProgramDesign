#include<stdio.h>

unsigned short swap_bytes(unsigned short i){
    return ((i<<8) & 0xff00) | ((i>>8) & 0x00ff);
}
int main(){
    unsigned short i;
    scanf("%hx", &i);
    printf("%hx", swap_bytes(i));

    return 0;
}
