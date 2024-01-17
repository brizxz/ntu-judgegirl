#include<stdbool.h>
#include<stdio.h>
struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *mid;
    struct TreeNode *right;
};
 
typedef struct TreeNode TreeNode;
 
bool isIsomorphic(TreeNode* root1, TreeNode* root2){
    if (root1== NULL && root2== NULL) return true;
    else if (root1==NULL && root2!=NULL || root1!=NULL && root2==NULL) return false;
    return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->mid, root2->mid) && isIsomorphic(root1->right, root2->right)) ||
    (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->mid) && isIsomorphic(root1->mid, root2->right)) ||
    (isIsomorphic(root1->left, root2->mid) && isIsomorphic(root1->mid, root2->right) && isIsomorphic(root1->right, root2->left)) ||
    (isIsomorphic(root1->left, root2->mid) && isIsomorphic(root1->mid, root2->left) && isIsomorphic(root1->right, root2->right)) ||
    (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->mid, root2->left) && isIsomorphic(root1->right, root2->mid)) ||
    (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->mid, root2->mid) && isIsomorphic(root1->right, root2->left));
}