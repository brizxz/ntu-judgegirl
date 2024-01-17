# include<stdio.h>
 
int min(int x, int y){
    if (x < y) return x;
    return y;
}
 
void place(char a[36],unsigned int n,char str1[],char str2[]){
    for (int i=0; i<sizeof(unsigned int)*8; i++){
        if  (n&1!=0){
            a[i] = str1[0];
        }
        else a[i] = str2[0];
        n>>=1;
    }
}
 
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    char str1[5],str2[5]; 
    scanf("%s%s",str1,str2);
    unsigned int num; int count = 0; int total = m*n;
    while(scanf("%d",&num)!=EOF){
        char a[36];
        place(a,num,str1,str2);
        for (int i=31; i>=((total>=32)?0:32-total); i--){
            printf("%c",a[i]);
            count++;
            if (count%m==0 && count!=0) printf("\n");
        }
        total-=32;
    }
}