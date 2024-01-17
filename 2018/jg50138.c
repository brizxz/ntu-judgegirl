#include <stdio.h>
 
typedef struct{
    int rawScore;
    double scaledScore;
}Score;
 
typedef struct{
    char id[10];
    Score score[18];
    double finalScore;
}Student;
 
typedef struct{
    int numStudent;
    Student student[1000];
}Classes;
 
void computeGrade(Classes classes[2]){
    for (int i= 0; i<18; i++){
        double class0_ave = 0; double class1_ave = 0;
        for (int j= 0; j<classes[0].numStudent; j++){
            class0_ave += classes[0].student[j].score[i].rawScore;
        }
        for (int j= 0; j<classes[1].numStudent; j++){
            class1_ave += classes[1].student[j].score[i].rawScore;
        }
        class0_ave /= classes[0].numStudent;
        class1_ave /= classes[1].numStudent;
        // printf("%f %f\n", class0_ave, class1_ave);
        if (class0_ave > class1_ave){
            double ratio = class0_ave / class1_ave;
            for (int j= 0; j<classes[1].numStudent; j++){
                classes[1].student[j].score[i].scaledScore = classes[1].student[j].score[i].rawScore*ratio;
                if (classes[1].student[j].score[i].scaledScore>100) classes[1].student[j].score[i].scaledScore=100;
            }
            for (int j= 0; j<classes[0].numStudent; j++) classes[0].student[j].score[i].scaledScore = classes[0].student[j].score[i].rawScore;
        }
        else{
            double ratio = class1_ave / class0_ave;
            for (int j= 0; j<classes[0].numStudent; j++){
                classes[0].student[j].score[i].scaledScore = classes[0].student[j].score[i].rawScore*ratio;
                if (classes[0].student[j].score[i].scaledScore>100) classes[0].student[j].score[i].scaledScore=100;
            for (int j= 0; j<classes[1].numStudent; j++) classes[1].student[j].score[i].scaledScore = classes[1].student[j].score[i].rawScore;
            }
        }
    }

    for (int i=0; i<2; i++){
        for (int j=0; j<classes[i].numStudent; j++){
            double grades = 0;
            for (int k=0; k<18; k++){
                grades += classes[i].student[j].score[k].scaledScore;
            }
            grades *= 0.06;
            if (grades>100) grades = 100;
            printf("%s %f\n",classes[i].student[j].id,grades);
        }
    }
}
