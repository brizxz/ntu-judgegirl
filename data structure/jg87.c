#include <stdio.h>
#include "node.h"
struct node *merge(struct node *list1, struct node *list2){
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    if (list1->value < list2->value){
        list1 -> next = merge(list1->next, list2);
        return list1;
    }
    else{
        list2 -> next = merge(list2->next, list1);
        return list2;   
    }
}