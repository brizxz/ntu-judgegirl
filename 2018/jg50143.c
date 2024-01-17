#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *treeAND(Node *root1, Node *root2){
    if (root1== NULL || root2== NULL) return NULL;
    Node *node1 = (Node*)malloc(sizeof(Node));
    node1->val = root1->val*root2->val;
    node1->left = treeAND(root1->left, root2->left);
    node1->right = treeAND(root1->right, root2->right);
    return node1;
}
Node *treeOR(Node *root1, Node *root2){
    if (root1== NULL && root2== NULL) return NULL;
    if (root1== NULL) return root2;
    else if (root2== NULL) return root1;
    Node *node1 = (Node*)malloc(sizeof(Node));
    node1->val = root1->val+root2->val;
    node1->left = treeOR(root1->left, root2->left);
    node1->right = treeOR(root1->right, root2->right);
    return node1;   
}
