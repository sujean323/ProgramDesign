#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int swap(int *a, int *b){
    int tmp = a;
    a = b;
    b = tmp;
}
int main(){
    int size;
    scanf("%d", &size);
    int a[size];
    int b[size];

    for(int i=0; i<size; i++)
        scanf("%d", a+i);//&a[i]
    for(int i=0; i<size; i++)
        scanf("%d", b+i);

    swap(a, b);

    printf("1st array: ");
    for(int i=0; i<size; i++)
        printf("%d ", *(b+i));
    printf("\n");
    printf("2nd array: ");
    for(int i=0; i<size; i++)
        printf("%d ", *(a+i));

    return 0;
}
