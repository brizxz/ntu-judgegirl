#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int small,large;
    struct node *left,*mid,*right;
}Node;

Node *gennode(int data1,int data2,Node *left,Node *mid ,Node *right){
    Node *node = (Node *)malloc(sizeof(Node));
    node->left = left;
    node->mid = mid;
    node->right = right;
    node -> small =data1;
    node -> large =data2;
    return node;
}

Node *insert(Node *root,int num){
    if (root == NULL) return gennode(-1,num,NULL, NULL, NULL);
    if (root->small == -1){
        if (num < root->large) root->small = num;
        else{
            int temp = root->large;
            root->small = root->large;
            root->large = num;
        }
    } 
    else if (num<root->small){
        root -> left = insert(root->left,num);
    }
    else if (num < root -> large) {
        root -> mid = insert(root->mid,num);
    }
    else {
        root -> right = insert(root->right,num);
    }
    return root;
}

Node *ConstructTree(int sequence[],int N){
    Node *root = NULL;
    for (int i = 0; i < N; i++){
        root = insert(root,sequence[i]);
    }

    return root;
}   