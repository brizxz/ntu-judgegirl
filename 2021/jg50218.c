#include <stdio.h>
#include "treeToList.h"

List buildlist(TreeNode * root){
    List list;
    list.head = list.tail = root;
    list.head->right = list.tail -> right = NULL;
    return list;
}

// 連接
List concat(List a, List b){
    if (a.head == NULL) return b;
    else if (b.head == NULL) return a;

    List c;
    c.head = a.head;
    a.tail->left = b.head;
    c.tail = b.tail;
    return c;
}

List treeToListFunc(TreeNode * root){
    if (root == NULL){
        List none;
        none.head = none.tail = NULL;
        return none;
    }

    List left = treeToListFunc(root->left);
    List right = treeToListFunc(root->right);

    if (root->value%2==0){
        return concat(buildlist(root),concat(left,right));
    }
    else{
        return concat(buildlist(root),concat(right,left));
    }

}