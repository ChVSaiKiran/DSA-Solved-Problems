class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int idx = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(abs(nums[i]) < abs(nums[idx])){
                idx = i;
            }
        }

        vector<int> ans;
        int i = idx, j = idx + 1;
        while(i >= 0 && j < n){
            if(abs(nums[i]) < abs(nums[j])){
                ans.push_back(nums[i] * nums[i]);   i--;
            } else{
                ans.push_back(nums[j] * nums[j]);   j++;
            }
        }

        while(i >= 0){
            ans.push_back(nums[i] * nums[i]);   i--;
        }

        while(j < n){
            ans.push_back(nums[j] * nums[j]);   j++;
        }

        return ans;
    }
};