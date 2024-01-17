#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *genNode(int data,Node *left, Node *right){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

Node *construct(Node *root, char instruction[MAXN]){
    if (root == NULL) root = genNode(1,NULL, NULL);
    else root->data ++;
    Node *cur = root;
    for (int i=0; instruction[i]!='\0'; i++){
        // printf("%c", instruction[i]);
        if (instruction[i]=='L'){
            if (cur->left==NULL){
                cur->left = genNode(1,NULL, NULL);
                cur = cur->left;
            }
            else{
                cur = cur->left;
                cur->data ++;
            }
        }
        else{
            if (cur->right==NULL){
                cur->right = genNode(1,NULL, NULL);
                cur = cur->right;
            }
            else{
                cur = cur->right;
                cur->data ++;
            }
        }
    }
    return root;
}
int query(Node *root, char instruction[MAXN]){
    Node *cur = root;
    if (root == NULL) return 0;
    for (int i=0; instruction[i]!='\0'; i++){
        if (instruction[i]=='L'){
            cur = cur-> left;
        }
        else{
            cur = cur-> right;
        }
        if (cur== NULL) return 0;
    }
    return cur ->data;
}