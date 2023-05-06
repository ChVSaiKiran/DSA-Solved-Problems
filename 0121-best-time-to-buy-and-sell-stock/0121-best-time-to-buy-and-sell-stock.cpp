class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> temp(n);
        for(int i = n - 2; i >= 0; i--)
            temp[i] = max(temp[i+1],prices[i+1]);
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans,temp[i] - prices[i]);
        return ans;
    }
};