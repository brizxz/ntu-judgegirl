#include <stdio.h>
typedef unsigned long long Set;
#define UINT64 unsigned long long
#define ll long long int 
void init(Set *set){
    ll k=0;
    *set = k;
}
void add(Set *set, int i){
    ll k=1;
    *set += (k<<(i-1));
}
void has(Set set, int i){
    ll k=1;
    if ((set&(k<<(i-1)))!=0) printf("set has %d\n",i);
    else printf("set does not have %d\n",i);
}
Set setUnion(Set a, Set b){
    return a|b;
}
Set setIntersect(Set a, Set b){
    return a&b;   
}
Set setDifference(Set a, Set b){
    return a^b;
}