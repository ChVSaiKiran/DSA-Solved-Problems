class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int l = 0, r = nums.size() - 1, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                ans[l++] = nums[i];
            }

            if(nums[n - i - 1] > pivot){
                ans[r--] = nums[n - i - 1];
            }
        }

        while(l <= r){
            ans[l++] = pivot;
        }

        return ans;
    }
};