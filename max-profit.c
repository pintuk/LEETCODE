#define INF 0x7fffffff

int maxProfit(int* prices, int pricesSize) {
    int i;
    int minvalue = INF;
    int maxprofit = 0;
    
    for (i = 0; i < pricesSize; i++) {
        int profit;
        
        profit = prices[i] - minvalue;
        if ((profit >= 0) && profit > maxprofit)
            maxprofit = profit;
        if (prices[i] < minvalue)
            minvalue = prices[i];
    }
    return maxprofit;
}
