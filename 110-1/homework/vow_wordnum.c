#include<stdio.h>
#include<ctype.h>

int main(){
    char ch, tmp = ' ';
    int vowel = 0;
    int word = 1;//space+1

    printf("Enter a sentence: \n");

    while((ch = getchar()) != EOF){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'  ){
            vowel++;
        }
        if(ch == ' ' && ch != tmp){
            word++;
        }
        tmp = ch;
    }

    printf("%d %d", vowel, word);

    return 0;
}
