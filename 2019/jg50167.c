double payment(int itemID[], double price[], int orderItemID[], int orderQuantity[], int onSaleItemID[]){
    int itemnum,ordernum,onsalenum; double sum=0;
    for (int i=0; i<20000; i++) if (itemID[i]==0) itemnum=i;
    for (int i=0; i<20000; i++) if (orderItemID[i]==0) ordernum=i;
    for (int i=0; i<20000; i++) if (onSaleItemID[i]==0) onsalenum=i;
    for (int i=0; i<ordernum; i++){
        for (int j=0; j<itemnum; j++){
            if (orderItemID[i]==itemID[j]){
                double pri=price[j]*orderQuantity[i];
                for (int k=0; k<onsalenum; k++){
                    if (orderItemID[i]==onSaleItemID[k]){
                        pri*=0.8; break;
                    }
                }
                sum+=pri;
                break;
            } 
        }
    }
    if (sum<490.00) sum+=80;
    return sum;
}