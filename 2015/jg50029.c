#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;
 
Node *genNode(int label,Node *left,Node *right){
    Node *node = (Node *)malloc(sizeof(Node));
    node->label = label;
    node-> left = left;
    node->right = right;
    return node;
}
 
Node *insertNode(Node *node,int array[],int n,int k){
    if (k>=n) return NULL;
    if (node==NULL) node = genNode(array[k],NULL, NULL);
    node->left = insertNode(node->left,array,n,2*k+1);
    node->right = insertNode(node->right,array,n,2*k+2);
 
    return node;
}
 
Node* construct(int array[], int n){
    Node *root= NULL;
    root = insertNode(root,array,n,0);
    return root;
}