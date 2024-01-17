# define ROW 3
# define COL 5
# include <string.h>
typedef int A[ROW][COL];
typedef int B[COL][ROW];
typedef int C[ROW][ROW];
 
// 可直接將void改為 int 
void multiplyMatrix(void ** arrayA, void ** arrayB, void ** arrayC){
    for (int i = 0; arrayA[i]!=NULL && arrayB[i]!=NULL && arrayC[i]!=NULL; i++){
        for (int j = 0; j <3; j++){
            for (int k = 0; k <3; k++){
                int sum=0;
                for (int l = 0; l <5; l++){
                    // we need to designate the data type when data is void
                    int a=*(*((int**)arrayA+i)+j*5+l); int b=*(*((int**)arrayB+i)+l*3+k);
                    //  &a:a[0][0]的地址
                    sum+= (a*b);
                }
                *(*((int**)arrayC+i)+j*3+k)=sum;
            }
        }
    }
}

/* fast
void multiplyMatrix(void ** arrayA, void ** arrayB, void ** arrayC)
{
    int **arrA = (int**) arrayA;
    int **arrB = (int**) arrayB;
    int **arrC = (int**) arrayC;
    for (int z=0;arrA[z]!=NULL;z++)
        for (int i=0;i<ROW;i++)
            for (int j=0;j<COL;j++)
            {
                arrC[z][i*ROW+j]=0;
                for (int k=0;k<COL;k++)
                {
                    arrC[z][i*ROW+j]+=arrA[z][i*COL+k]*arrB[z][k*ROW+j];
                }
            }
}
*/