#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct person{
    unsigned int id;
    char name[32];
    unsigned hash_value;
}person;
typedef struct friends {
    unsigned id1;
    unsigned id2;
}friends;
unsigned hash(char *S){
    return (*S)? (*S)+256*hash(S+1) : 0;
}
int cmp(const void *a,const void *b){
    return ((person*)a)->hash_value > ((person*)b)->hash_value ? 1 : ((person*)a)->hash_value < ((person*)b)->hash_value ? -1 : 0;
}
int cmp2(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}
int P_size,F_size;
person P[10001];
friends F[10001];
short count[10001],now[10001]={0};
int *map[10001];
int main(){
    FILE *fin=fopen("friends","rb");
    fread(&P_size,4,1,fin);
    for(int i=0;i<P_size;i++){
        fread(&P[i],36,1,fin);
        P[i].hash_value=hash(P[i].name);
    }
    fread(&F_size,4,1,fin);
    fread(F,sizeof(friends),F_size,fin);
    for(int i=0;i<F_size;i++){
        if(F[i].id1 > F[i].id2){
            F[i].id1 ^= F[i].id2 ^= F[i].id1 ^= F[i].id2 ;
        }
        count[F[i].id1]++;
    }
    for(int i=0;i<P_size;i++){
        map[P[i].id]=(int*)malloc(sizeof(int)*count[P[i].id]);
    }
    for(int i=0;i<F_size;i++){
        map[F[i].id1][now[F[i].id1]++]=F[i].id2;
    }
    for(int i=0;i<P_size;i++){
        qsort(map[P[i].id],count[P[i].id],sizeof(int),cmp2);
    }
    qsort(P,P_size,sizeof(person),cmp);
    char S1[32],S2[32];
    person t1,t2;
    friends f;
    while(scanf("%s%s",S1,S2)==2){
        t1.hash_value=hash(S1),t2.hash_value=hash(S2);
        int id1=((person*)bsearch(&t1,P,P_size,sizeof(person),cmp))->id;
        int id2=((person*)bsearch(&t2,P,P_size,sizeof(person),cmp))->id;
        if(id1>id2){
            id1^=id2^=id1^=id2;
        }
        puts(bsearch(&id2,map[id1],count[id1],sizeof(int),cmp2)? "yes" : "no");
    }
}