#include<stdio.h>
#include<math.h>

struct polynomial{
    long int coef;
    long int exp;
};struct polynomial p[100];

int main(){
    long int term, times, x, ans=0;
    //Enter the number of terms
    while(scanf("%ld", &term)){
        if(term<=0){
            printf("The number must be greater than zero!\n");
        }
        else break;
    }
    //Enter each term with cof and exp
    for(int i=0; i<term; i++){
        scanf("%ld %ld", &p[i].coef, &p[i].exp);
    }
    //display the polynomial form
    for(int i=0; i<term; i++){
        printf("%ldx^%ld ", p[i].coef, p[i].exp);
        if(i<term-1){
            printf("+ ");
        }
    }
    printf("=\n");
    //How many times to calculate
    scanf("%ld", &times);
    while(times<=0){
        printf("The number must be greater than zero!\n");
        scanf("%ld", &times);
    }
    for(int i=0; i<times; i++){
        while(scanf("%ld", &x)){
            if(x<=0){ //waring message
                printf("The number must be greater than zero!\n");
            }
            else break;
        }
        for(int j=0; j<term; j++){
            ans += p[j].coef*pow(x, p[j].exp);
        }
        printf("%ld\n", ans);
        ans=0;
    }

    return 0;
}
