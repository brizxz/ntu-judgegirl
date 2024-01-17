#include<stdio.h>
#include"merge.h"
#include<stdlib.h>
 
Node *merge(Node *list[], int K){
 
    Node* last=NULL;
    Node* first=NULL;
 
    for(int i=0; i<K; i++){
        if(list[i]==NULL){
            continue;
        }
        if(last!=NULL) last->next=list[i];
        else first=list[i];
        last=list[i];
        if(list[i]->next!=NULL){
            list[i]=list[i]->next;
        }
        else list[i]=NULL;
    }
    if (first==NULL) return NULL;
 
    for(int i=0; i<K/2; i++){
        Node* tmp = list[i];
        list[i] = list[K-i-1];
        list[K-i-1] = tmp;
    }
 
    last->next=merge(list,K);
    return first;
}