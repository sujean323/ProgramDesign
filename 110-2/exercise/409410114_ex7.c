#include<stdio.h>
#include<string.h>

struct records{
    int id;
    int score;
};
void bubble_sort(int n, struct records sort[]){
    struct records tmp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(sort[j].id>sort[j+1].id){
                tmp = sort[j];
                sort[j] = sort[j+1];
                sort[j+1] = tmp;
            }
        }
    }
    for(int k=0; k<n; k++){
        printf("%d\t%d\n", sort[k].id, sort[k].score);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    struct records sort[n];
    for(int i=0; i<n; i++)
        scanf("%d %d", &sort[i].id, &sort[i].score);
    printf("ID\tscore\n");
    bubble_sort(n, sort);

    return 0;
}
/*using bubble sort
store all the numbers into array
using two for loop to compare each adjacent numbers
if the previous number is greater than the next one then swapping them
each iteration move the greatest number to rear
because there are n numbers to be sorted
and variable i make sure the last one is the greatest
therefor, we should repeat n-1 times to complete
the variable j change depending on how many numbers already sorted
so it decrease along with the sorted numbers increasing
*/
