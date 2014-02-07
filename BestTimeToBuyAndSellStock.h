/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

class Solution {
public:

    int maxProfit(vector<int> &prices) {
        if(prices.size()<2)
            return 0;
        
        int min = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i]<min){
                min = prices[i];
            }
            else{
                maxProfit = max(maxProfit, prices[i]-min);
            }
        }
        return maxProfit;
    }
};