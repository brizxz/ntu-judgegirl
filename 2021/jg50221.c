#include <stdio.h>
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

void setfill(Node *node_array, int height){
    int maxindex = height*(height+1)/2-1;
    int right = 0; int righth=height-1;
    while (right < maxindex) {
        for (int i = right; i < right+righth; i++) {
            node_array[i].left->value += node_array[i].value;
            node_array[i].right->value += node_array[i].value;
        }
        right += (righth+1);
        righth--;
    }
}

void build_Pascal(Node* node_array, int height){
    int maxindex = height*(height+1)/2-1;
    node_array[0].value=1;

    // connect right
    int right = 0; int righth=height-1;
    while (right < maxindex) {
        for (int i = right; i < right+righth; i++) {
            node_array[i].right = &node_array[i+1];
        }
        right += (righth+1);
        righth--;
    }
    //connect left
    int leftk = height-1; int calleft = height; int h=0; 
    for (int i=0; i < leftk; i++) {
       int j = calleft; int k=i; int hei = h; 
       while(j>=2){
            if (k+j>maxindex || hei>=height-1) break;
            node_array[k].left = &node_array[k+j];
            k+=j;
            j--; hei++;
        }
        h++;
    }
    setfill(node_array,height);
}