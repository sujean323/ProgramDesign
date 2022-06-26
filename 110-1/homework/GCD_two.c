#include<stdio.h>

int main(){
    int m,n;

    printf("Enter two integers: \n");
    scanf("%d%d", &m, &n);//input

    while(n!=0){
        int tmp = m%n;
        m = n;
        n = tmp;
    }

    printf("The GCD number is:%d", m);

    return 0;
}
