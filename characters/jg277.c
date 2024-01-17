#include <stdio.h>
#include <string.h>
 
void printnum(char k,int w,int d,int h){
    if (d==0){
        if (k=='1' || k=='4'){
            for (int i=0; i<w; i++) printf(" ");
        }
        else{
            printf(" ");
            for (int i=1; i<w-2; i++) printf("%c",k);
            printf("  ");
        }
    }
    else if (d==h-1){
        if (k=='1' || k=='4' || k=='7' || k=='9') {
            for (int i=0; i<w; i++) printf(" ");
        }
        else{
            printf(" ");
            for (int i=1; i<w-2; i++) printf("%c",k);
            printf("  ");
        }        
    }
    else if (d==(h/2)){
        if (k=='1' || k=='0' || k=='7') {
            for (int i=0; i<w; i++) printf(" ");
        }
        else{
            printf(" ");
            for (int i=1; i<w-2; i++) printf("%c",k);
            printf("  ");
        }        
    }
    else if (d<(h/2)){
        if (k=='4' || k=='0' || k=='7' || k=='8' || k=='9') {
            printf("%c",k);
            for (int i=1; i<w-2; i++) printf(" ");
            printf("%c ",k); 
        }
        else if (k=='5' || k=='6'){
            printf("%c",k);
            for (int i=1; i<w; i++) printf(" ");
        }   
        else{
            for (int i=0; i<w-2; i++) printf(" ");
            printf("%c ",k);       
        }     
    }
    else{
        if (k=='6' || k=='0' || k=='8' ) {
            printf("%c",k);
            for (int i=1; i<w-2; i++) printf(" ");
            printf("%c ",k); 
        }
        else if (k=='2'){
            printf("%c",k);
            for (int i=1; i<w; i++) printf(" ");
        }   
        else{
            for (int i=0; i<w-2; i++) printf(" ");
            printf("%c ",k);       
        }            
    }
}
 
int main(){
    char str[20]; int num[10][15][9];
    while (scanf("%s", str)!=EOF){
        int w,h;
        scanf("%d%d", &w, &h);
        for (int i =0; i<h; i++){
            for (int j=0; j<strlen(str); j++) printnum(str[j],w,i,h);
            printf("\n");
        }
    }
}