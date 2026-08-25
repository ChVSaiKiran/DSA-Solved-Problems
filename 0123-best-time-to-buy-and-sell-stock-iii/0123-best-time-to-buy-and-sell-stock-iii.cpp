class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int minVal = INT_MAX, prefixProfix = 0;
        vector<int> prefix(n);
        for(int i = 0; i < n; i++){
            minVal = min(minVal, prices[i]);
            prefixProfix = max(prefixProfix, prices[i] - minVal);
            prefix[i] = prefixProfix;
        }

        int maxVal = INT_MIN, suffixProfix = 0;
        vector<int> suffix(n);
        for(int i = n - 1; i >= 0; i--){
            maxVal = max(maxVal, prices[i]);
            suffixProfix = max(suffixProfix, maxVal - prices[i]);
            suffix[i] = suffixProfix;
        }

        int res = prefixProfix;
        for(int i = 0; i < n - 1; i++){
            res = max(res, prefix[i] + suffix[i + 1]);
        }

        return res;
    }
};