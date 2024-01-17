#include<stdio.h>
#include"BuildTree.h"
 
Node* split(Node* list){
    Node* ptr=list;
    int i=0;
    for (i=0; ptr!=NULL; i++) ptr=(ptr->left);
    int ll=i-(i/2);
    if (i<=1) return NULL;
    ptr=list;
    for (int j=1; j<ll; j++){
        ptr=(ptr->left);
    }
    Node* tmp=ptr->left;
    ptr->left=NULL;
    return tmp;
}
 
 
Node* BuildTree(Node* list1, Node* list2){
    if (list1==NULL && list2==NULL) return NULL;
    Node* cur;
    if (list1==NULL) return list2;
    if (list2==NULL) return list1;
 
    if (list1->val > list2->val){
        cur=list2;
        Node* secondL1= split(list1);
        Node* secondL2= split(list2->left);
        cur->left=BuildTree(list1, list2->left);
        cur->right=BuildTree(secondL1, secondL2);
        return cur;
    }
    if (list1->val < list2->val){
        cur=list1;
        Node* secondL1= split(list1->left);
        Node* secondL2= split(list2);
        cur->left=BuildTree(list1->left, list2);
        cur->right=BuildTree(secondL1, secondL2);
        return cur;
    }
}