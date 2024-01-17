#include <stdio.h>
#include <string.h>
typedef struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
} emplo;
int main(){
    int n; emplo worker[32];
    scanf("%d",&n);
    for (int i = 0; i <n; i++) {
        scanf("%d%s%s%d",&worker[i].id, worker[i].first_name, worker[i].last_name, &worker[i].boss_id);
    }
    int q;
    scanf("%d",&q);
    for (int i = 0; i <q; i++){
        char af[100]; char al[100]; char bf[100]; char bl[100]; 
        scanf("%s%s%s%s",af,al,bf,bl);
        int find=0;
        char ans[4][15]={"unrelated","subordinate","supervisor","colleague"}; // a是b的()
        int ansa[32]; int ansb[32];
        int loc_a=0,loc_b=0;
        int c_a=0; int c_b=0; 
        for (int i = 0; i <n; i++){
            if (strcmp(worker[i].first_name,af)==0 && strcmp(worker[i].last_name,al)==0) loc_a=i;
            if (strcmp(worker[i].first_name,bf)==0 && strcmp(worker[i].last_name,bl)==0) loc_b=i;
        }
        int aid=worker[loc_a].id; int bid=worker[loc_b].id; 
        while (worker[loc_a].id != worker[loc_a].boss_id){
            for (int i = 0; i <n; i++){
                if (worker[i].id==worker[loc_a].boss_id){
                    ansa[c_a]=worker[i].id; c_a++; loc_a=i;
                    break;
                }
            }
        }
        while (worker[loc_b].id != worker[loc_b].boss_id){
            for (int i = 0; i <n; i++){
                if (worker[i].id==worker[loc_b].boss_id){
                    ansb[c_b]=worker[i].id; c_b++; loc_b=i;
                    break;
                }
            }
        }
        for (int i = 0; i <c_a; i++){
            if (ansa[i]==bid) find=1;
        }
        for (int i = 0; i <c_b; i++){
            if (ansb[i]==aid) find=2;
        }
        if (find==0){
            for (int i = 0; i <c_a; i++){
                for (int j = 0; j <c_b; j++){
                    if (ansa[i]==ansb[j]) find =3;
                }
            }
        }
        printf("%s\n",ans[find]);
    }
}