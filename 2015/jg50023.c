#ifndef _LOCKER_H
#define _LOCKER_H
 
typedef struct lock{
    int arr[4];
    int s;
} Lock;
 
void init(Lock *lock){
    for (int i=0; i<4; i++) lock->arr[i] = 0;
    lock->s = 0;
}
int lock(Lock *lock, int combination){
    if (lock->s != 0) return -1;
    if (combination>=10000 || combination<0) return 10000;
    lock -> arr[0] =combination/1000;
    lock -> arr[1] =(combination%1000)/100;
    lock -> arr[2] =(combination%100)/10;
    lock -> arr[3] =(combination%10);
    lock -> s = 1;
    return combination;
}
int unlock(Lock *lock, int combination){
    if (lock->s == 0) return -1;
    int judge = lock->arr[0]*1000 + lock->arr[1]*100 + lock->arr[2]*10 + lock->arr[3]; 
    if (judge==combination){
        lock->s = 0;
        return 0;
    } 
    return 1;
}
int isLocked(Lock *lock){
    if (lock->s == 0) return 0;
    return 1;
}
#endif