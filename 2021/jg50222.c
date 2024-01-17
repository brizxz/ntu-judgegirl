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
    char input[80];
    char output[80];
    int sec;
    scanf("%s%s%d", input, output, &sec);

    FILE *in = fopen(input,"rb");
    Wav res;
    fread(&res, sizeof(Wav), 1, in);

    FILE *out = fopen(output,"wb");
    res.data_size =res.bit_rate*sec;
    res.t_blocksize = res.data_size+36;

    fwrite(&res,sizeof(Wav),1, out);
    short content[res.bit_rate*sec];
    fread(&content, sizeof(short),res.sample_freq*sec,in);
    fwrite(&content,sizeof(short),res.sample_freq*sec,out);

    fclose(in);
    fclose(out);
}