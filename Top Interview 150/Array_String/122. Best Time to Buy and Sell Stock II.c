int maxProfit(int* prices, int n){
    if(n == 1) return 0;
    int profit = 0;
    for(int i = 1; i < n; i++){
        profit += (prices[i] > prices[i-1] ? prices[i] - prices[i-1] : 0);
    }
    return profit;
}