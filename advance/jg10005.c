# include<stdio.h>
# include<string.h>
 
int main(){
    char str[1024]; int status = 0;
    while(scanf("%s", str) != EOF){
        for (int i = 0; i <strlen(str); i++){
            if (str[i]<48 || str[i]>57){
                if (str[i-1]>=48 && str[i-1]<=57 && i!=0) printf("\n");
                status = 0;
                continue;
            }
            else{
                if ((str[i-1]<48 || str[i-1]>57) && (str[i]=='0') && (str[i+1]<48 || str[i+1]>57)) printf("%d",0);
                else if ((str[i-1]<48 || str[i-1]>57) && (str[i]=='0') && (str[i+1]=='0') && (str[i+2] <'0' || str[i+2]>'9')) printf("%d",0);
                else if (str[i]>=49 && str[i]<=57 ){
                    printf("%c",str[i]);
                    status = 1;
                }
                if (status==1 && str[i]=='0') printf("%d",0);
            }
            if (i==strlen(str)-1 && str[i]<=57 && str[i]>=48) printf("\n"); 
        }
    }
}