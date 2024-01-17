# include <stdio.h>
int main(){
 
    int n;
    int judge[200000];
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        int x1,y1,x2,y2,x3,y3,x4,y4;
        scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
 
        int x12= (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1); int x13= (x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
        int x14= (x4-x1)*(x4-x1) + (y4-y1)*(y4-y1); int x23= (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
        int x24= (x4-x2)*(x4-x2) + (y4-y2)*(y4-y2); int x34= (x4-x3)*(x4-x3)+(y4-y3)*(y4-y3);
        if (((x12+x23==x13)&&(x14+x34==x13)&&(x12+x14==x24))||((x12+x24==x14)&&(x13+x34==x14)&&(x12+x13==x23))||((x13+x14==x34)&&(x13+x23==x12)&&(x24+x14==x12))){
            if(((x12==x23)&&(x23==x34)&&(x34==x14))||((x12==x24)&&(x24==x34)&&(x34==x13))||((x13==x23)&&(x23==x24)&&(x24==x14)))
                judge[i]=1;
            else judge[i]=3;
        }
        else{
            if(((x12==x23)&&(x23==x34)&&(x34==x14))||((x12==x24)&&(x24==x34)&&(x34==x13))||((x13==x23)&&(x23==x24)&&(x24==x14)))
                judge[i]=2;
            else
                judge[i]=4;
        }
    }
    for (int i=0; i<n; i++){
        if (judge[i]==1) printf("square\n");
        else if (judge[i]==2) printf("diamond\n");
        else if (judge[i]==3) printf("rectangle\n");
        else if (judge[i]==4) printf("other\n");
    }
}