class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long val = 1, ans = 0, j = 0;
        if(k == 0){
            return ans;
        }
        for(int i = 0; i < nums.size(); i++){
            val *= nums[i];
            while(val >= k && j <= i){
                val /= nums[j++];    
            }
            ans += (i - j + 1);
        }
        return ans;
    }
};