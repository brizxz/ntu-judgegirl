#include <stdio.h>
 
int main(void) {
  int x1,y1,z1,x2,y2,z2;
  scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
  int inner= x1*x2+y1*y2+z1*z2;
  int outerx = x1*y2-x2*y1;
  int outery = y1*z2-z1*y2;
  int outerz = z1*x2-z2*x1;
  printf("%d\n%d %d %d\n",inner,outery,outerz,outerx);
}