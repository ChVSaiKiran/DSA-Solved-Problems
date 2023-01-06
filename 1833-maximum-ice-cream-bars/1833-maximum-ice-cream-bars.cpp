class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans = 0, i = 0, n = costs.size();
        while(i < n && costs[i] <= coins){
            ans++;
            coins = coins - costs[i];
            i++;
        }
        return ans;            
    }
};