#include <stdio.h>
#include <stdlib.h>
#include "construct.h"
#include <stdint.h>

Node *genNode(int value,Node *left,Node *right){
    Node *node = (Node *)malloc(sizeof (Node));
    node -> value = value;
    node -> left = left;
    node -> right = right;
    return node;
}

int findbalance(int T[],int N,int start,int end){
    if (end-start<2) return -1;
    int64_t k = 0; int64_t kk=0;
    for (int i=start; i<=end; i++){
        k+= T[i];
        kk += i*T[i];
    }
    if (kk%k==0) return kk/k;
    return -1;
}

Node *genlist(int T[],int N ,int start,int end){
    if (end < start) return NULL;
    return genNode(T[end],genlist(T,N,start,end-1),NULL);
}

Node *gentree(int T[], int N,int start,int end){
    if (start>end) return NULL;

    int balance = findbalance(T,N,start,end);
    if (balance == -1){
        return genlist(T,N,start,end);
    }
    else return genNode(T[balance],gentree(T,N,start,balance-1),gentree(T,N,balance+1,end));
}

Node *ConstructTree(int T[], int N){
    return gentree(T,N,0,N-1);
}
