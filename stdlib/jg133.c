#include <stdio.h>
#include <string.h>
struct string_count {
        char seen[80];
        int count;
};
int compare_and_add(char *string, struct string_count strings[]) {
    for (int i = 0; ; i++){
        if (strcmp (string,strings[i].seen) == 0){
            strings[i].count++;
            return 1;
        } 
        if (strings[i].count==0){
            strcpy(strings[i].seen,string);
            strings[i].count++; 
            break;
        }
    }
    return 0;
}
void sort(struct string_count strings[]) {
    int num = 0;
    for (int i = 0; strings[i].count!=0; i++) num++;
    for (int i = num-2; i >=0; i--){
        for (int j = 0; j <=i; j++){
            if (strings[j].count > strings[j+1].count || 
            strings[j].count == strings[j+1].count && strcmp(strings[j].seen,strings[j+1].seen)>0){
                char temp[80]; int temp1;
                temp1 = strings[j].count; strings[j].count = strings[j+1].count; strings[j+1].count = temp1;
                strcpy(temp,strings[j].seen); strcpy(strings[j].seen,strings[j+1].seen);
                strcpy (strings[j+1].seen,temp);
            }
        }
    }
}
void print(struct string_count strings[]) {
    int num = 0;
    for (int i = 0; strings[i].count!=0; i++) num++;
    for (int i = 0; i<num; i++) printf("%d %s\n",strings[i].count,strings[i].seen);
}