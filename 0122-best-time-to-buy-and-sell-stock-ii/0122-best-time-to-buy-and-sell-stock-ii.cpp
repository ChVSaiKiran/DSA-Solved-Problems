class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0,  buy = prices[0];
        for(int i : prices){
            if(buy < i)
                profit += (i - buy);
            buy = i;
        }
        return profit;
    }
};