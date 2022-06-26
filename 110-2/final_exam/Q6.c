#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;//t
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;//candy cookie
        scanf("%d %d", &x, &y);
        if (x > 2*y || y > 2*x || (x+y) % 3) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}
