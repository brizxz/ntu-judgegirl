#include <stdio.h>
#include <stdlib.h>
// important concept
typedef struct listnode {
    int data;
    struct listnode *next;
    struct listnode *prev;
} ListNode;
 
typedef struct linkedlist{
    struct listnode *head;
    struct listnode *tail;
} LinkedList;

void insert(LinkedList *list, int data){
    ListNode *now=list->head;
    ListNode *newnode= (ListNode *)malloc(sizeof(ListNode));
    newnode->data=data;
    if(now==NULL){
        newnode->next=newnode->prev=NULL;
        list->head=list->tail=newnode;
        return;
    }
    if(now->data>data){
        newnode->next=list->head;
        newnode->prev=NULL;
        (list->head)->prev=newnode;
        list->head=newnode;
        return;
    }
    while(now!=list->tail){
        if(now->data<=data&&(now->next)->data>data){
            newnode->prev=now;
            newnode->next=now->next;
            ((now->next)->prev)=newnode;
            now->next=newnode;
            return;
        }
        now=now->next;
    }
    newnode->prev=list->tail;
    newnode->next=NULL;
    (list->tail)->next=newnode;
    list->tail=newnode;
    return;
}
 
void delete_head(LinkedList *list){
    if((list->head)->next==NULL){
        list->head=list->tail=NULL;
        return;
    }
    list->head=(list->head)->next;
    (list->head)->prev=NULL;
}
void delete_tail(LinkedList *list){
    if((list->tail)->prev==NULL){
        list->tail=list->head=NULL;
        return;
    }
    list->tail=(list->tail)->prev;
    (list->tail)->next=NULL;
}