class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> closest(n, 0);
        closest[0] = 1; closest[n - 1] = n - 2;

        for(int i = 1; i < n - 1; i++){
            closest[i] = abs(nums[i] - nums[i - 1]) <= abs(nums[i] - nums[i + 1]) ? i - 1 : i + 1;
        }

        vector<int> preSum(n, 0);
        for(int i = 1; i < n; i++){
            preSum[i] = preSum[i - 1] + (closest[i - 1] == i ? 1 : abs(nums[i] - nums[i - 1]));
        }

        vector<int> suffSum(n, 0);
        for(int i = n - 2; i >= 0; i--){
            suffSum[i] = suffSum[i + 1] + (closest[i + 1] == i ? 1 : abs(nums[i] - nums[i + 1]));
        }

        vector<int> res;
        res.reserve(queries.size());

        for(auto &it: queries){
            int l = it[0], r = it[1];
            if(l < r){
                res.push_back(min(preSum[r] - preSum[l], abs(nums[l] - nums[r])));
            } else{
                res.push_back(min(suffSum[r] - suffSum[l], abs(nums[l] - nums[r])));
            }
        }

        return res;
    }
};