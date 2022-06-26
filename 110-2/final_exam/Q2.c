#include<stdio.h>

int main(){
    int a, b, c, m;
    scanf("%d %d %d %d", &a, &b, &c, &m);
    int r = c % m;
    int r2 = c % m + m;
    for(int i=a; i<=b; i++) {
       if (i % m == r || (i % m) + m == r || (i % m) + m == r + m || (i % m) == r2) {
           printf("%d ", i);
       }
    }
    printf("\n");
    return 0;
}

