class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> temp(n);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    temp[i] = max(temp[i], temp[j] + 1);
                }
            }
        }
        

        int idx = 0;
        for(int i = 1; i < n; i++){
            if(temp[idx] < temp[i]){
                idx = i;
            }
        }

        int prevIdx = idx;
        vector<int> ans(1, nums[idx--]);
        while(idx >= 0){
            if(nums[prevIdx] % nums[idx] == 0 && temp[prevIdx] == temp[idx] + 1){
                prevIdx = idx;
                ans.push_back(nums[idx]);
            }
            idx--;
        }

        return ans;
    }
};