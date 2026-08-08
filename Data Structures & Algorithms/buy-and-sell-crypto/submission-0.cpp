class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int j=1;
        int buy=prices[0], max_profit = 0;
        while(j<prices.size()){
            if(prices[j] < buy){
                buy=prices[j];
            } else {
                int current_profit = prices[j] - buy;
                if (current_profit > max_profit) {
                    max_profit = current_profit;
                }
            }
            j++;
        }
        return max_profit;
    }
};