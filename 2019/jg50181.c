#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct node{
    struct node* rightPtr;
    struct node* downPtr;
}NODE;
typedef struct Point
{
  NODE *ptr;
  int level;
} point;

point godown(NODE *head,int level){
    assert(head!=NULL);
    while(head->downPtr != NULL){
        level++;
        head = head->downPtr;
    }
    point down = {head,level};
    return down;
}

int area(point up,point down){
    int ans=0;
    while(up.level < down.level){
        ans += (down.level - up.level);
        up = godown(up.ptr->rightPtr,up.level);
        down = godown(down.ptr->rightPtr,down.level);
    }
    return ans;
}

int calArea(NODE* head){
    point up ={head,0};
    point down =godown(head,0);
    return area(up,down);
}