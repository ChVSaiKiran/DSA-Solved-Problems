class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, mini = prices[0];
        for(int i : prices){
            profit = max(profit, i - mini);
            mini = min(i, mini);
        }
        return profit;
    }
};