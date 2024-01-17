#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "construct.h"
 
Node *genbstree(int weight,char name[16],int height,Node *left, Node *right){
    Node *node = (Node *)malloc(sizeof(Node));
    node->weight = weight;
    node->height = height;
    strcpy(node->name,name);
    node->left = left;
    node->right = right;
    return node;
}
#ifdef WEIGHT
Node *insertw(Node *root,int weight,char name[16],int height){
    if (root==NULL){
        return  genbstree(weight,name,height,NULL,NULL);
    } 
    if (weight < root->weight) root->left = insertw (root->left,weight,name,height);
    else if (weight > root->weight) root-> right = insertw (root->right,weight,name,height);
    return root;
}

#endif
#ifdef HEIGHT
Node *insertw(Node *root,int weight,char name[16],int height){
    if (root==NULL){
        return  genbstree(weight,name,height,NULL,NULL);
    } 
    if (height < root->height) root->left = insertw (root->left,weight,name,height);
    else if (height > root->height) root-> right = insertw (root->right,weight,name,height);
    return root;
}
#endif
Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]){
    Node *root = NULL;
    for (int i=0; i<N; i++){
        root = insertw(root,weight[i],name[i],height[i]);
    } 
    return root;
}
