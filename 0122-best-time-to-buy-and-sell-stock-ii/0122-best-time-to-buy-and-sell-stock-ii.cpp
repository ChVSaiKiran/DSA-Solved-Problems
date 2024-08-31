class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, prev = prices[0];
        for(int i : prices){
            if(i > prev){
                profit += (i - prev);
            }
            prev = i;
        }
        return profit;
    }
};