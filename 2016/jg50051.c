#include <string.h>
#include <stdio.h>
#include <ctype.h>

int judge(char c[10]){
    if (c[2]=='-') return 1;
    else if (c[3]=='-') return 2;
    return -1; // maybe have no '-'
}
int ifvalid(char c){
    if ((c<='9' && c>='0') || (c>='a' && c<='z') || (c>='A' && c<='Z')) return 1;
    return 0;
}
void bbsort(char type[31][10],int c){
    char temp[10];
    if (c==1 || c==0) return;
    else if (c==2){
        if (strcmp(type[0],type[1])>0){
            strcpy(temp,type[0]);
            strcpy(type[0],type[1]);
            strcpy(type[1],temp); 
        }
    }
    else{
        for (int i=c-2;i>=0; i--){
            for (int j=0; j<=i; j++){
                if (strcmp(type[j],type[j+1])>0){
                    strcpy(temp,type[j]);
                    strcpy(type[j],type[j+1]);
                    strcpy(type[j+1],temp); 
                }
            }
        }
    }

}
int main(){
    int n; int counttype1=0, counttype2=0;
    scanf("%d",&n);
    char type2[31][10], type1[31][10];
    for (int i=0; i<n; i++){
        char str[10]; int judge7=0;
        scanf("%s",str);
        if (judge(str)==1){
            int l=0; int ll=0;
            for (int i=0; i<7; i++){
                if (i==2) continue;
                if (isdigit(str[i])) l++;
                if (ifvalid(str[i])==0) ll=1;
            }
            for (int i=0; i<7; i++) if (isdigit(str[i])) judge7+=(str[i]-'0');
            if (judge7%7==0 || l==0 || ll==1) continue;
            char count[7]; int cou[7]={0};
            for (int i=0; i<7; i++){
                count[i]=str[i]; cou[i]=1;
            } 
            for (int i=0; i<7; i++){
                for (int j=i+1; j<7; j++){
                    if (str[j]==count[i]) cou[i]++;
                }
            }
            int find=0;
            for (int i=0; i<7; i++){
                if (cou[i]>2) find=1;
            }      
            if (find==1) continue;    
            if ((str[0]==str[1] && str[1]=='4') || (str[3]==str[4] && str[3]=='4') 
            || (str[4]==str[5] && str[4]=='4') || (str[5]==str[6] && str[5]=='4')) continue;
            strcpy(type1[counttype1],str);
            counttype1++;
        }
        else if (judge(str)==2){
            int l=0; int ll=0;
            for (int i=0; i<7; i++){
                if (i==3) continue;
                if (isdigit(str[i])) l++;
                if (ifvalid(str[i])==0) ll=1;
            }
            for (int i=0; i<7; i++) if (isdigit(str[i])) judge7+=(str[i]-'0');
            if (judge7%7==0 || l==0 || ll==1) continue;
            char count[7]; int cou[7]={0};
            for (int i=0; i<7; i++){
                count[i]=str[i]; cou[i]=1;
            } 
            for (int i=0; i<7; i++){
                for (int j=i+1; j<7; j++){
                    if (str[j]==count[i]) cou[i]++;
                }
            }
            int find=0;
            for (int i=0; i<7; i++){
                if (cou[i]>2) find=1;
            }      
            if (find==1) continue;    
            if ((str[0]==str[1] && str[1]=='4') || (str[1]==str[2] && str[1]=='4') 
            || (str[4]==str[5] && str[4]=='4') || (str[5]==str[6] && str[5]=='4')) continue;
            strcpy(type2[counttype2],str);
            counttype2++;
        }
    }
    bbsort(type1,counttype1); bbsort(type2,counttype2);
    for (int i=0; i<counttype1; i++) printf("%s\n",type1[i]);
    for (int i=0; i<counttype2; i++) printf("%s\n",type2[i]);
}