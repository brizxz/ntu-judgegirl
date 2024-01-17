int min(int a, int b){
    if (a < b) return a;
    return b;
}
int max(int a, int b){
    if (a < b) return b;
    return a;
}
int abs(int a){
    if (a < 0) return -a;
    return a;
}
// RGB:0,1,2
int stationDistance(int R_distance[],int G_distance[],int B_distance[],int G_origin,int G_destination,int startStation[],int endStation[]){
    int d=0;
    if (startStation[0]==endStation[0]){
        int start=min(startStation[1],endStation[1]); int end=max(startStation[1],endStation[1]);
        for (int i=start; i<end; i++){
            if (startStation[0]==0) d+=R_distance[i-1];
            else if (startStation[0]==1) d+=G_distance[i-1];
            else if (startStation[0]==2) d+=B_distance[i-1];
        }
    }
    else if (startStation[0]==0 && endStation[0]==1){
        int start=min(startStation[1],G_origin); int end=max(startStation[1],G_origin);       
        for (int i=start; i<end; i++) d+=R_distance[i-1];
        for (int i=1; i<endStation[1] ; i++) d+=G_distance[i-1];
    }
    else if (startStation[0]==0 && endStation[0]==2){
        int start=min(startStation[1],G_origin); int end=max(startStation[1],G_origin);       
        for (int i=start; i<end; i++) d+=R_distance[i-1];
        for (int i=1; G_distance[i-1]!=0 ; i++) d+=G_distance[i-1];
        start=min(endStation[1],G_destination); end=max(endStation[1],G_destination);
        for (int i=start; i<end; i++) d+=B_distance[i-1];
    }
    else if (startStation[0]==1 && endStation[0]==0){
        int start=min(endStation[1],G_origin); int end=max(endStation[1],G_origin);       
        for (int i=start; i<end; i++) d+=R_distance[i-1];
        for (int i=startStation[1]-1; i>0 ; i--) d+=G_distance[i-1];
    }
    else if (startStation[0]==1 && endStation[0]==2){
        int start=min(endStation[1],G_destination); int end=max(endStation[1],G_destination);       
        for (int i=start; i<end; i++) d+=B_distance[i-1];
        for (int i=startStation[1]; G_distance[i-1]!=0 ; i++) d+=G_distance[i-1];
    }
    else if (startStation[0]==2 && endStation[0]==1){
        int start=min(startStation[1],G_destination); int end=max(startStation[1],G_destination);       
        for (int i=start; i<end; i++) d+=B_distance[i-1];
        for (int i=endStation[1]; G_distance[i-1]!=0; i++) d+=G_distance[i-1];
    }
    else if (startStation[0]==2 && endStation[0]==0){
        int start=min(startStation[1],G_destination); int end=max(startStation[1],G_destination);       
        for (int i=start; i<end; i++) d+=B_distance[i-1];
        for (int i=1; G_distance[i-1]!=0 ; i++) d+=G_distance[i-1];
        start=min(endStation[1],G_origin); end=max(endStation[1],G_origin);
        for (int i=start; i<end; i++) d+=R_distance[i-1];
    }
    return d;
}
