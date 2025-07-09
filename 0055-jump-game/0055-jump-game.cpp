class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> temp(n, false);

        for(int i = n - 2; i >= 0; i--){
            for(int d = 1; d <= nums[i]; d++){
                temp[i] = (i + d >= n - 1) || temp[i + d];
                if(temp[i]){
                    break;
                }
            }
        }

        return n == 1 || temp[0];
    }
};