class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0];
        int profit = 0;

        for(int i=1; i<prices.size(); i++){
            if(prices[i] < bestBuy){
                bestBuy = prices[i];
            }
            profit = max(prices[i]-bestBuy,profit);
        }
        return profit;
    }
};
