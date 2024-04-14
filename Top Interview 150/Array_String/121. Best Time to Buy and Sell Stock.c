int maxProfit(int* prices, int size){
    int minprice = prices[0];
    int maxprofit = 0, i, temp;
    for(i = 0; i < size; i++){
        if(prices[i] < minprice){
            minprice = prices[i];
        }
        else{
            temp = prices[i] - minprice;
            if(temp > maxprofit){
                maxprofit = temp;
            }
        }
    }
    return maxprofit;
}