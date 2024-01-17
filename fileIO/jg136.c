#include <stdio.h>
typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;
 
int main(){
    char filein[85];
    char fileout[85];
    scanf("%s%s",filein,fileout); 
    FILE *open = fopen(filein,"rb");
    FILE *output = fopen(fileout,"w");
    Student a;
    fprintf(output,"<table border=\"1\">\n");
    fprintf(output,"<tbody>\n");
    while (fread(&a,sizeof(Student),1,open)){
        fprintf(output,"<tr>\n");
 
        fprintf(output,"<td>%s</td>\n",a.name);
        fprintf(output,"<td>%d</td>\n",a.id);
        fprintf(output,"<td>%s</td>\n",a.phone);
        fprintf(output,"<td>%f, %f, %f, %f</td>\n",a.grade[0],a.grade[1],a.grade[2],a.grade[3]);
        fprintf(output,"<td>%d, %d, %d</td>\n",a.birth_year,a.birth_month,a.birth_day);
        fprintf(output,"</tr>\n");
 
    }
    fprintf(output,"</tbody>\n");
    fprintf(output,"</table>\n");
 
    fclose(open);
    fclose(output);
}