#include<stdio.h>
#include<stdlib.h>

int cmp(const void * a, const void * b) {
    int _a = *(int*)a, _b = *(int*)b;
    if ((_a % 2) && !(_b % 2)) return -1;
    if (!(_a % 2) && (_b % 2)) return 1;
    return _a > _b;
}
int main(){
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(arr[0]), cmp);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
