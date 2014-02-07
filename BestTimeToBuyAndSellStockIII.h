/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:

    int maxProfit(vector<int> &prices) {
        
        if(prices.size()<2){
            return 0;
        }
        
        vector<int> profitUtil(prices.size(),0);
        vector<int> profitFrom(prices.size(),0);
        
        int min = prices[0];
        int profit = 0;
        for(int i= 1; i < prices.size(); ++i){
            if(prices[i]<min){
                min=prices[i];
            }
            else{
                profit = std::max(profit,prices[i]-min);
            }
            profitUtil[i] = profit; 
        }
        
        profit = 0;
        int max= prices[prices.size()-1];
        
        for(int i = prices.size()-2; i >=0 ; --i){
            if(prices[i]>max){
                max = prices[i];
            }
            else{
                profit = std::max(profit, max - prices[i]);
            }
            profitFrom[i] = profit;
        }
        
        //once transaction
        int maxOne = profit;
        
        //at most twice
        int maxTwo = 0;
        for(int i = 1; i < prices.size()-2; ++i){
            maxTwo = std::max(maxTwo, profitUtil[i]+profitFrom[i+1] );
        }
        
        return std::max(maxOne,maxTwo);
    }
    
};
