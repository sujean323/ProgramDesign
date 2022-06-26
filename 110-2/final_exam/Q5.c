#include<stdio.h>

int main(){
    int t, a, b, can, coo;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d %d", &a, &b);
        for(int j=0; j<1000000000; j++){
            a = a-2;
            b = b-1;
            if(a+b==0){
                printf("YES\n");
                break;
            }
            else if(a<0||b<0){
                printf("NO\n");
                break;
            }
            can = a-1;
            coo = b-2;
            if(can+coo==0){
                printf("YES\n");
                break;
            }
            else if(can<0||coo<0){
                printf("NO\n");
                break;
            }
        }
    }

    return 0;
}
