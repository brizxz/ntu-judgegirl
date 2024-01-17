#include <stdio.h>
#include <string.h>
#define maxL 1000
typedef struct Submission
{
    int subID;
    int studentID;
    char outputs[10][maxL];   
}Submission;
int calscore(char answer[10][maxL],Submission k){
    int sum=0;
    for (int i=0; i<10; i++){
        if (strcmp(answer[i],k.outputs[i])==0) sum+=10;
    }  
    return sum;
}

void grading(char answer[10][maxL], Submission* sub, int num_of_submission){
    int output[100][3]; int maxscore=0;
    for (int i =0; i<num_of_submission; i++){
        output[i][0] = sub[i].subID; output[i][1] = sub[i].studentID;
        output[i][2] = calscore(answer, sub[i]);
    }
    for (int i=num_of_submission-2; i>=0; i--){
        for (int j=0; j<=i; j++){
            if (output[j][1]>output[j+1][1] || output[j][1]==output[j+1][1] && output[j][0]>output[j+1][0]){
                int temp = output[j+1][1]; output[j+1][1] = output[j][1]; output[j][1] = temp;
                temp = output[j+1][0]; output[j+1][0] = output[j][0]; output[j][0] = temp;
                temp = output[j+1][2]; output[j+1][2] = output[j][2]; output[j][2] = temp;
            }
        }
    }
    for (int i=0; i<num_of_submission; i++){
        if (output[i][2]>maxscore) maxscore = output[i][2];
        printf("Student %d gets %d with Submission %d.\n",output[i][1],output[i][2],output[i][0]);
        if (i!=num_of_submission-1 && output[i][1]!=output[i+1][1] ){
            printf("Student %d gets %d in this exam.\n",output[i][1],maxscore); maxscore=0;  
        } 
    }
    printf("Student %d gets %d in this exam.\n",output[num_of_submission-1][1],maxscore);
}