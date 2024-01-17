#include "node.h"
#include <stdio.h>
struct node *getNode(struct node *head, unsigned int i){
    int count=0;
    struct node* ans = head;
    struct node* ans1 = head;
    while (ans != NULL){
        count++;
        ans = ans->next;
    } 
    if (i>count) return NULL;
    int c= count-1;
    while (ans1 != NULL){
        if (c==i) return ans1;
        c--;
        ans1 = ans1->next;
    }
}