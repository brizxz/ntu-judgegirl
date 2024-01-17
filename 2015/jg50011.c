#include <stdio.h>
#include <string.h>
char dic[100000][110];
int main(){

    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%s",dic[i]);
    }
    int q;
    scanf("%d",&q);
    for (int i=0; i<q; i++){
        char search[101]; char candi[200][110]; int c_candi=0; int kk=0;
        scanf("%s",search);
        for (int j=0; j<n; j++){
            int s1=strlen(search); int s2=strlen(dic[j]);
            if (strcmp(dic[j],search)==0){
                printf(">%s\n",dic[j]); kk=1;
                break;
            }
            else if (s1==s2){
                int dif=0;
                for (int k=0; k<s1; k++){
                    if (dic[j][k]!=search[k]) dif++;
                }
                if (dif>1) continue;
                else{ 
                    strcpy(candi[c_candi],dic[j]); c_candi++; kk=2;
                }
            }
            else if (s1-s2==1){
                int judge=0; int z=0;
                for (int k=0; k<s2; k++,z++){
                    if (search[z]!=dic[j][k] && judge==0){
                        judge=1; z+=1;
                        if (search[z]!=dic[j][k]) judge=2;
                    }
                    else if (search[z]!=dic[j][k] && judge==1) judge=2;
                }
                if (judge==1 || strncmp(search,dic[j],s2)==0){
                    strcpy(candi[c_candi],dic[j]); c_candi++; kk=2;
                }
            }
            else if (s2-s1==1){
                int judge=0; int z=0;
                for (int k=0; k<s1; k++,z++){
                    if (search[k]!=dic[j][z] && judge==0){
                        judge=1; z+=1;
                        if (search[k]!=dic[j][z]) judge=2;
                    }
                    else if (search[k]!=dic[j][z] && judge==1) judge=2;
                }
                if (judge==1 || strncmp(search,dic[j],s1)==0){
                    strcpy(candi[c_candi],dic[j]); c_candi++; kk=2;
                }
            }
        }
        if (kk==0) printf("!%s\n",search);
        else if (kk==2){
            printf("?");
            for (int j=0; j<c_candi; j++){
                if (j==0) printf("%s",candi[j]);
                else printf(" %s",candi[j]);
            }
            printf("\n");
        }
    }
}