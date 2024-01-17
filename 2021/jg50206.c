#include <stdio.h>
#include <string.h>

int cal(char c[4]){
    int place = (c[0]-'a')*26*26+(c[1]-'a')*26+(c[2]-'a');
    return place;
}

int main(){
    char buf[100000];
    int count[30000]; 
    for (int i=0; i<30000; i++) count[i]=0;
    while(scanf("%s",buf) !=EOF){
        for (int i=2;i<strlen(buf); i++){
            char c[4];
            c[0]=buf[i-2]; c[1]=buf[i-1]; c[2]=buf[i]; c[3]='\0';
            count[cal(c)]++;
        }
    }
    // for (int i=0; i<countch; i++) printf("%s\n",ans[i]);
    char final[3][5]; int finalc[3]={0,0,0}; // max second third
    for (int i=0; i<26*26*26; i++){
        if (count[i]<finalc[2]) continue;
        char cc[4]; 
        cc[0]= 'a'+i/(26*26);cc[1]= 'a'+(i%(26*26))/26;cc[2]= 'a'+i%26;
        if (count[i]>finalc[0] || count[i]==finalc[0] && strcmp(cc,final[0])<0){
            finalc[2]=finalc[1]; finalc[1]=finalc[0]; finalc[0]=count[i];
            strcpy(final[2],final[1]); strcpy(final[1],final[0]); strcpy(final[0],cc);
        }
        else if (count[i]>finalc[1] || count[i]==finalc[1] && strcmp(cc,final[1])<0){
            finalc[2]=finalc[1]; finalc[1]=count[i];
            strcpy(final[2],final[1]); strcpy(final[1],cc); 
        }
        else if (count[i]>finalc[2] || count[i]==finalc[2] && strcmp(cc,final[2])<0){
            finalc[2]=count[i];
            strcpy(final[2],cc);
        }
    }
    printf("%s\n%s\n%s",final[0],final[1],final[2]);
}