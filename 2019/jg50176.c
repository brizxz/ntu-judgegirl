#include <stdio.h>
typedef struct bid {
  int bidderID;
  int itemID;
  int bidPrice;
} Bid;
 
typedef struct itemMinPrice{
  int itemID;
  int minPrice;
} ItemMinPrice;
void bidding(Bid bidSeq[], int m, ItemMinPrice minPriceSeq[], int n){
    Bid winner[1100]; int find[1100]={0};
    for (int i=0; i<n; i++) {
        find[i]=0;
        winner[i].itemID = minPriceSeq[i].itemID;
        winner[i].bidPrice = minPriceSeq[i].minPrice;
    }
    for (int i=n-2; i>=0; i--){
        for (int j=0; j<=i; j++){
            if (winner[j].itemID>winner[j+1].itemID){
                int temp = winner[j].itemID;
                winner[j].itemID = winner[j+1].itemID;
                winner[j+1].itemID = temp;
                temp = winner[j].bidPrice;
                winner[j].bidPrice = winner[j+1].bidPrice;
                winner[j+1].bidPrice = temp;
            }
        }
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++) {
            if ((bidSeq[i].itemID == winner[j].itemID && bidSeq[i].bidPrice>=winner[j].bidPrice && find[j]==0)
            || (bidSeq[i].itemID == winner[j].itemID && bidSeq[i].bidPrice>winner[j].bidPrice && find[j]==1)){
                find[j]=1; winner[j].bidderID=bidSeq[i].bidderID; winner[j].bidPrice=bidSeq[i].bidPrice; 
            }
        }
    }
    for (int i=n-2; i>=0; i--){
        for (int j=0; j<=i; j++){
            if (winner[j].bidderID>winner[j+1].bidderID){
                int temp = winner[j].itemID;
                winner[j].itemID = winner[j+1].itemID;
                winner[j+1].itemID = temp;
                temp = winner[j].bidderID;
                winner[j].bidderID = winner[j+1].bidderID;
                winner[j+1].bidderID = temp;
                temp = winner[j].bidPrice;
                winner[j].bidPrice = winner[j+1].bidPrice;
                winner[j+1].bidPrice = temp;          
                temp = find[j]; find[j]= find[j+1]; find[j+1]=temp;     
            }
        }
    }
    for (int i=0; i<n; i++){
        if (find[i]==1){
            printf("Bidder %d gets item %d with %d dollars\n",winner[i].bidderID,winner[i].itemID,winner[i].bidPrice);
        }
    }
}