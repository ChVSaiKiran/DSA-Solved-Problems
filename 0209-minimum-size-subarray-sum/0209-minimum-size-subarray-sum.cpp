class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0, sum = 0, len = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                len = min(i - j + 1, len);
                sum -= nums[j++];
            }
        }

        if(len == INT_MAX){
            len = 0;
        }
        
        return len;
    }
};