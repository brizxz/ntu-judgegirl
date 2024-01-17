void init(int length[3]) {
    /* add your code */
    length[0] = length[1] = length[2] = 0;
}
void add(int length[3], int i) {
    /* add your code */
    length[2]+=i; 
    if (length[2]>11){
        length[1]+=(length[2]/12);
        length[2]%=12;
    }
    if (length[1]>2){
        length[0]+=(length[1]/3);
        length[1]%=3;
    }
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
    /* add your code */
    int i = (lengtha[0]+lengthb[0])*36+(lengtha[1]+lengthb[1])*12+(lengtha[2]+lengthb[2]); 
    init(lengthc); add(lengthc,i);
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    /* add your code */
    int i = (lengtha[0]-lengthb[0])*36+(lengtha[1]-lengthb[1])*12+(lengtha[2]-lengthb[2]);
    init(lengthc); add(lengthc,i);
}