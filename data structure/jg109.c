#include "node.h"
#include <stdio.h>
void print_array(int ans[],int n){
    for (int i = 0; i < n-1; i++) printf("%d ",ans[i]);
    printf("%d\n",ans[n-1]);
}
 
void print_recur(struct node *root,int arr[],int n){
    if (root == NULL) return;
    arr[n]=root->data;
    n++;
    if (root->left == NULL && root->right == NULL) print_array(arr,n);
    else {
        print_recur(root->left,arr,n);
        print_recur(root->right,arr,n);
    }
}
 
void print_all_paths(struct node *root){
    int arr[1000];
    print_recur(root,arr,0);
}