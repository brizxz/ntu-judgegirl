#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *left, *right;
} Node;
 
Node *genNode(int data,Node *left, Node *right){
    Node *node = (Node *)malloc(sizeof (Node));
    node -> n = data;
    node -> left = left;
    node -> right = right;
    return node;
}

Node *insertNode(Node *new,Node *root){
    if (root == NULL) return NULL;
    if (new == NULL){
        if (root -> left == NULL  && root -> right == NULL){
            return genNode(root->n , NULL, NULL); 
        }
        else if (root -> left == NULL){
            new = genNode(root->n,NULL, NULL);
            new -> left = insertNode(new->left,root->right);
        }
        else if (root -> right == NULL){
            new = genNode(root->n,NULL, NULL);
            new -> right = insertNode(new->right,root->left);
        }
        else{
            new = genNode(root->n,NULL, NULL);
            new -> left = insertNode (new->left,root->right);
            new -> right = insertNode (new->right,root->left);
        }
    }

    return new;
}



Node *FlipTree(Node *root){
    Node *new = NULL;
    new = insertNode (new,root);
    return new;
}
int isIdentical(Node *tree1, Node *tree2){
    if (tree1==NULL && tree2==NULL) return 1;
    if (tree1==NULL || tree2== NULL || tree1->n != tree2->n) return 0;
    return isIdentical(tree1->left,tree2->left) && isIdentical(tree1->right,tree2->right);
}

int calroot(Node *root){
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return calroot(root->left)+calroot(root->right);
}
int cal_level(Node *root,int level){
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return level;
    
    return cal_level(root->left,level+1) + cal_level(root->right,level+1);
}

void depthAvg(Node *root){
    Node *buf = root;
    int total_num = calroot(buf);
    int depth = cal_level(root,0);
    printf("%d/%d\n",depth,total_num);
}
