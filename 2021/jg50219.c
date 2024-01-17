#include <stdio.h>
#include <stdlib.h>
 
typedef struct wav{
    char block_code[4];
    int t_blocksize;
    char file_format[4];
    char block1_label[4];
    int block1_size;
    short music_format;
    short music_channel;
    int sample_freq;
    int bit_rate;
    short blockpair;
    short bit_width;
    char block2_label[4];
    int data_size;
} Wav;
 
int main(){
    char file1[80]; char file2[80]; char res[80];
    scanf("%s%s%s", file1, file2, res);
    Wav a,b,c;
    FILE *fin = fopen(file1, "rb");
    FILE *fout = fopen(file2, "rb");
    FILE *foutput3 = fopen(res, "wb");

    fread(&a, sizeof(Wav), 1, fin);
    fread(&b, sizeof(Wav), 1, fout);

    c = a;
    c.data_size = a.data_size + b.data_size ;
    c.t_blocksize = c.data_size + 36;
    short contenta[a.data_size];
    short contentb[b.data_size];
    fwrite(&c,sizeof(Wav),1, foutput3);

    fread(&contenta, sizeof(short),a.data_size,fin);
    fread(&contentb, sizeof(short),b.data_size,fout);

    fwrite(&contenta,sizeof(short),a.data_size/2,foutput3);
    fwrite(&contentb,sizeof(short),b.data_size/2,foutput3);

    fclose(fin);
    fclose(fout);
    fclose(foutput3);
}