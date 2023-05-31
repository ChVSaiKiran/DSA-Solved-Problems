class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n && nums[i] < 0; i++)
            nums[i] = abs(nums[i]);
        int i = 0;
        while(i < n - 1 && nums[i] >= nums[i + 1])
            i++;
        int j = i + 1;
        vector<int> ans;
        while(i >= 0 && j <= n - 1){
            int temp = nums[i] <= nums[j] ? nums[i] * nums[i--] : nums[j] * nums[j++];
            ans.emplace_back(temp);
        }
        while(i >= 0)
            ans.emplace_back(nums[i] * nums[i--]);
        while(j <= n - 1)
            ans.emplace_back(nums[j] * nums[j++]);
        return ans;
    }
};