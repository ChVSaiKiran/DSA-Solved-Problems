class Solution {
private:
    int fun(vector<int> &nums, int k){
        int cnt = 0, l = 0, ans = 0;
        for(int r = 0; r < nums.size(); r++){
            cnt += (nums[r] % 2);
            while(cnt > k){
                cnt -= (nums[l++] % 2);
            }
            if(cnt <= k){
                ans += (r - l + 1);
            } 
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k - 1);
    }
};