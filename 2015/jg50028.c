#include <stdio.h>

typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;
 
int dfs(Node *root,int k,int **p){
    if (root == NULL) return 0;
    int left = dfs(root->left,k,p);
    int right = dfs(root->right,k,p);

    if (left && right && root->label!=k){
        // 用指標來移動 陣列順序
        (*p)[0] = root->label;
        (*p)++;
    }
    return (root->label==k) || left || right;
}

int getNode(Node *root, int label[], int k){
    int *p  = label;
    dfs(root, k,&p);
    return p-label;
}
 