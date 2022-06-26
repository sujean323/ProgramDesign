#include<stdio.h>

int check(char tmp){
    //check whether the user logs in more than 3 times or not.
    if(tmp>=3){
        printf("GOOD BYE\n");
        return 0;
    }
    else{
        printf("PASS\n");
        return 1;
    }
}
void user_login(int n, int id, unsigned char table[]){
    int index = id/4;
    int cla = id%4;
    unsigned char tmp;
    if(cla==0){
        tmp = table[index];
        tmp <<= 6;
        tmp >>= 6;
        if(check(tmp)==1)
            table[index] += 1;
    }
    else if(cla==1){
        tmp = table[index];
        tmp <<= 4;
        tmp >>= 6;
        if(check(tmp)==1)
            table[index] += 4;
    }
    else if(cla==2){
        tmp = table[index];
        tmp <<= 2;
        tmp >>= 6;
        if(check(tmp)==1)
            table[index] += 16;
    }
    else if(cla==3){
        tmp = table[index];
        tmp >>= 6;
        if(check(tmp)==1)
            table[index] += 64;
    }
}
int main(){
    //The integer n in the first line represents the number of the users (n must be divisible by 4).
    int n, id;
    scanf("%d", &n);
    unsigned char table[n/4]; //1 byte divided by 4 -> 2 bits
    memset(table, 0, n/4);
    //input the User ID which represents login until EOF
    while((scanf("%d", &id))!=EOF){
        user_login(n, id, table);
    }
    return 0;
}
