class Solution {
private:
    int f(vector<int> &nums, int i, int prevInd, vector<vector<int>> &dp){
        if(i == nums.size()){
            return 0;
        }

        if(dp[i][prevInd + 1] != -1){
            return dp[i][prevInd + 1];
        }

        int pick = 0, notPick = f(nums, i + 1, prevInd, dp);
        if(prevInd == -1 || nums[i] % nums[prevInd] == 0){
            pick = 1 + f(nums, i + 1, i, dp);
        }

        return dp[i][prevInd + 1] = max(pick, notPick);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // For Length
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // return f(nums, 0, -1);

        int n = nums.size(), maxInd = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(1);
        for(int i = 1; i < n; i++){
            hash.push_back(i);
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > dp[maxInd]){
                maxInd = i;
            }
        }

        vector<int> ans;
        while(hash[maxInd] != maxInd){
            ans.push_back(nums[maxInd]);
            maxInd = hash[maxInd];
        }
        ans.push_back(nums[maxInd]);
        return ans;        
    }
};