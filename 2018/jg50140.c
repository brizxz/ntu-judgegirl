#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct fb{
    char first;
    char last;
} fbits;

char cal(char dict[17],int k){
    return dict[k];
}
int find(char dict[17],char k){
    for (int i=0; i<16; i++){
        if (dict[i]==k) return i;
    }
}
fbits convert(int k, char dict[17]){
    int fir = k>>4;
    int las = (k&15);
    fbits a;
    a.first = cal(dict,fir);
    a.last = cal(dict,las);
    return a;
}

void bin2ascii(char input_file[32], char output_file[32], char dict[17]){
    FILE *op = fopen(input_file, "rb");
    FILE *output = fopen(output_file,"wb");
    int arr[1000000]; int count = 0; int only;
    while(fread(&only,1,1,op)){
        fbits buf;
        buf = convert(only,dict);
        fwrite(&buf.first,1,1,output);  
        fwrite(&buf.last,1,1,output);    
    }
    fclose(op);
    fclose(output);
}
void ascii2bin(char input_file[32], char output_file[32], char dict[17]){
    FILE *op = fopen(input_file, "rb");
    FILE *output = fopen(output_file,"wb");
    char arr[2]; int count = 0; 
    while(fread(arr,1,2,op)){
        int f = find(dict,arr[0]);
        int l = find(dict,arr[1]);
        int fl = (f<<4) | l;
        fwrite(&fl,1,1,output);
    }
}
