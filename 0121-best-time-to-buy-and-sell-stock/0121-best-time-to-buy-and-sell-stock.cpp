class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* Psudo Code & solution thinking,
        1. iterate over the prices, hold the maxSell , minBuy, maxProfit;
        2.A --> when you update the minBuy update maxSell respectively;
        2.B --> when you update maxSell don't have to update minBuy;
        3.A ---> update the maxProfit = max(maxSell-minBuy,maxProfit);
        3.B return the maxProfit

        time complexity O(n), space complexity O(1); 
        */

        if(prices.size() == 1)
            return 0;

        int maxProfit = 0, minBuy = prices[0];

        for(int i = 0 ; i < prices.size();i++)
        {
            if(prices[i] < minBuy)
                minBuy = prices[i];

            maxProfit = max((prices[i]-minBuy),maxProfit);
        }

        return maxProfit;
        
    }
};