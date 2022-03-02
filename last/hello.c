#include<stdio.h>

int main(){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* p = &a[0];
    printf("%d\n", *p++);//1
    printf("%d\n", *(p++));//1
    printf("%d\n", (*p)++);//1
    printf("%d\n", *++p);//2
    printf("%d\n", *(++p));//2
    printf("%d\n", ++*p);//2
    printf("%d\n", ++(*p));//2

    return 0;
}
