# include <stdio.h>
 
int main(){
    int n,i;
    scanf("%d%d",&n,&i);
    switch(i){
        case 1:
        printf("%d\n",n);
        break;
        case 2:
        printf("%d\n",n*n);
        break;
        case 3:
        printf("%d\n",n*n*n);
        break;
        case 4:
        printf("%d\n",n*n*n*n);
        break;
        case 5:
        printf("%d\n",n*n*n*n*n);
        break;
        default:
        break;
    }
}
