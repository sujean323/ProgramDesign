#include <stdio.h>
#include <stdlib.h> //qsort
#include <string.h>

struct para{
    char name[50];
    char attribute[10];
    int attack;
    int hp;
    int tag; //classify attribute
};
/*Sort the pokemon according to their name. Use a dictionary order to sort
the name from smallest to largest (we will guarantee that every
pokemon¡¦s name is distinct in the test data).*/
int cmp_name(const void *p1, const void *p2){
    return strcmp(p1, p2);
}
/*Sort the pokemon according to the attribute. The priority of the attribute
is WATER > FIRE > EARTH > LIGHT > DARK. The pokemon
with a higher priority should be printed first than the pokemon with a
lower one.
If the two pokemon have the same attribute, which HP is less should be
printed first.*/
int cmp_attribute(const void *p1, const void *p2){
    struct para *a = p1;
    struct para *b = p2;
    if(a->tag == b->tag){
        return a->hp - b->hp;
    }
    return b->tag - a->tag;
}
/*Sort the pokemon according to the attack value from largest to smallest
(we will guarantee every pokemon¡¦s attack value is different).*/
int cmp_attack(const void *p1, const void *p2){
    struct para *a = p1;
    struct para *b = p2;
    return b->attack - a->attack;
}
/*Sort the pokemon according to the hp value from smallest to largest. (we
will guarantee every pokemon¡¦s hp value is distinct)*/
int cmp_hp(const void *p1, const void *p2){
    struct para *a = p1;
    struct para *b = p2;
    return a->hp - b->hp;
}
int main(){
    int n, m; //give n pokemon, m queries
    scanf("%d %d", &n ,&m);
    struct para sort[n];
    for(int i=0; i<n; i++){
        scanf("%s %s %d %d", &sort[i].name, &sort[i].attribute, &sort[i].attack, &sort[i].hp);
    }
    for(int i=0; i<n; i++){
        if(strcmp(sort[i].attribute, "WATER") == 0){
            sort[i].tag = 5;
        }
        else if(strcmp(sort[i].attribute, "FIRE") == 0){
            sort[i].tag = 4;
        }
        else if(strcmp(sort[i].attribute, "EARTH") == 0){
            sort[i].tag = 3;
        }
        else if(strcmp(sort[i].attribute, "LIGHT") == 0){
            sort[i].tag = 2;
        }
        else if(strcmp(sort[i].attribute, "DARK") == 0){
            sort[i].tag = 1;
        }
    }
    for(int i=0; i<m; i++){
        char query[10];
        scanf("%s", query);
        if(strcmp(query, "NAME")==0){
            qsort(sort, n, sizeof(sort[0]), cmp_name);
            printf("Case #%d:\n", i+1);
            for(int j=0; j<n; j++){
                printf("%s %s %d %d\n", sort[j].name, sort[j].attribute, sort[j].attack, sort[j].hp);
            }
        }
        else if(strcmp(query, "ATTRIBUTE")==0){
            qsort(sort, n, sizeof(sort[0]), cmp_attribute);
            printf("Case #%d:\n", i+1);
            for(int j=0; j<n; j++){
                printf("%s %s %d %d\n", sort[j].name, sort[j].attribute, sort[j].attack, sort[j].hp);
            }
        }
        else if(strcmp(query, "ATTACK")==0){
            qsort(sort, n, sizeof(sort[0]), cmp_attack);
            printf("Case #%d:\n", i+1);
            for(int j=0; j<n; j++){
                printf("%s %s %d %d\n", sort[j].name, sort[j].attribute, sort[j].attack, sort[j].hp);
            }
        }
        else if(strcmp(query, "HP")==0){
            qsort(sort, n, sizeof(sort[0]), cmp_hp);
            printf("Case #%d:\n", i+1);
            for(int j=0; j<n; j++){
                printf("%s %s %d %d\n", sort[j].name, sort[j].attribute, sort[j].attack, sort[j].hp);
            }
        }
    }
    return 0;
}
