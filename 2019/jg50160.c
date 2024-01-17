#include <stdio.h>

int main(){
    int round;
    scanf("%d",&round);
    int h,g;  
    scanf("%d%d",&h,&g); int max=h;
    int s1[3]; int s2[3]; int s3[3]; int normal; // b,e,c
    int s1f=-1,s2f=-1,s3f=-1; // first time
    scanf("%d%d%d",&s1[0],&s1[1],&s1[2]);
    scanf("%d%d%d",&s2[0],&s2[1],&s2[2]);
    scanf("%d%d%d",&s3[0],&s3[1],&s3[2]);
    scanf("%d",&normal);
    for (int i=0; i<round; i++){
        int s1atk=0,s2atk=0,s3atk=0;
        if (i<=s1[2] && s1f==-1) s1atk=s1[0]; 
        else{
            if (s1f==-1 && i>s1[2]) s1atk=(s1[0]+s1[1]*(i-s1[2]));
            else if(i-s1f>=s1[2]) s1atk=(s1[0]+s1[1]*(i-s1[2]-s1f)); 
        }
        if (i<=s2[2] && s2f==-1) s2atk=s2[0]; 
        else{
            if (s2f==-1 && i>s2[2]) s2atk=(s2[0]+s2[1]*(i-s2[2]));
            
            else if(i-s2f>=s2[2]) s2atk=(s2[0]+s2[1]*(i-s2[2]-s2f));  
        }
        if (i<=s3[2] && s3f==-1) s3atk=s3[0]; 
        else{
            if (s3f==-1 && i>s3[2]) s3atk=(s3[0]+s3[1]*(i-s3[2]));
            else if(i-s3f>=s3[2]) s3atk=(s3[0]+s3[1]*(i-s3[2]-s3f));  
        }
        int attack;
        if (s1atk>=s2atk && s1atk>=s3atk && s1atk>=normal){
            attack = s1atk; s1f=i;
        } 
        else if (s2atk>=s1atk && s2atk>=s3atk && s2atk>=normal){
            attack = s2atk; s2f=i;
        } 
        else if (s3atk>=s1atk && s3atk>=s2atk && s3atk>=normal){
            attack = s3atk; s3f=i;
        } 
        else attack=normal;
        h-=attack; 
        if (i==0) printf("%d",h);
        else printf(" %d",h);
        if (h<=0) break;
        h = (h+g>max) ? max : h+g;
    }
}