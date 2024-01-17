#include <stdio.h>
#include <stdlib.h>
#include "construct.h"

Node *genlistnode(int value, Node *left, Node *right){
    Node *listnode = (Node *)malloc(sizeof(Node));
    listnode->value = value;
    listnode->left = left;
    listnode->right = right;
    return listnode;
}

Node *genlist(int sequence[],int N,int start,int end){
    if (start >end ) return NULL;
    return genlistnode(sequence[end],genlist(sequence,N,start,end-1),NULL);
}

int compare (const void *a, const void *b){
    int *c1 = (int *)a;
    int *c2 = (int *)b;
    return *c1>*c2;
}

int findNlargest(int sequence[], int N,int start,int end){
    int len = end - start+1;
    if (len<MAXLENGTH) return -1;

    int temp[16385];
    for (int i = 0; i < len; i++){
        temp[i] = sequence [start+i];
    }
    qsort (temp,len, sizeof(int),compare); // 1 2 3 4 5  3
    for (int i = start; i <=end; i++){
        if (sequence[i]== temp[len - MAXLENGTH]) return i;
    }

    return -1;
}

Node *gentree(int sequence[],int N,int start,int end){
    if (start >end) return NULL;

    int k = findNlargest(sequence,N,start,end);
    if (k==-1) return (genlist(sequence,N,start,end));

    else return genlistnode(sequence[k],gentree(sequence,N,start,k-1),gentree(sequence,N,k+1,end));
}

Node *ConstructTree(int sequence[], int N){
    return gentree(sequence,N,0,N-1);
}

