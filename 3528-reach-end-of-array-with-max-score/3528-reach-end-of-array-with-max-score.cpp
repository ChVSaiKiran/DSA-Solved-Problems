class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0, i = 0, n = nums.size();
        while(i < n){
            int j;
            for(j = i + 1; j < n; j++){
                if(nums[j] > nums[i]){
                    break;
                }
            }

            if(j < n){
                ans += (j - i) * nums[i];
            } else{
                ans += (n - 1 - i) * nums[i];
            }
            i = j;
        }
        return ans;
    }
};