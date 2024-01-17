#include <stdio.h>
#include "tree.h"
 
 
void traversal(Node *root, int N, int command[]){
    Node *path[1000];
    int end = 0;
    int cur = 0;
    path[0] = root;
    for (int i = 0; i<N && !end; i++){
        switch(command[i]){
            case 0:
                printf("%d\n",path[cur]->label);
                end = 1;
                break;
            case 1:
                printf("%d\n",path[cur]->label);
                break;
            case 2:
                if (cur>0){
                    cur--;
                }
                else {
                    printf("%d\n",path[cur]->label);
                    end = 1;
                }
                break;
            case 3:
                if (path[cur]->left == NULL){
                    printf("%d\n",path[cur]->label);
                    end = 1;
                }
                else{
                    cur++;
                    path[cur] = path[cur-1]->left;
                }
                break;
            case 4:
                if (path[cur]->right == NULL){
                    printf("%d\n",path[cur]->label);
                    end = 1;
                }
                else{
                    cur++;
                    path[cur] = path[cur-1]->right;
                }
                break;
            case 5: // go to sibling, the same height 
                if (path[cur-1]->left == path[cur]){
                    if (path[cur-1]->right== NULL){
                        printf("%d\n",path[cur]->label);
                        end = 1;
                    }
                    else{
                        path[cur] = path[cur-1]->right;
                    }
                }
                else{
                    if (path[cur-1]->left== NULL){
                        printf("%d\n",path[cur]->label);
                        end = 1;
                    }
                    else{
                        path[cur] = path[cur-1]->left;
                    }
                }
                break;
            default: 
                printf("%d\n",path[cur]->label);
                end = 1;
                break;
        }
    }
}
 
 
