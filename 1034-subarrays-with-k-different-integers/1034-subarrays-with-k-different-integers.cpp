class Solution {
private:
    int fun(vector<int> &nums, int k){
        long cnt = 0, l = 0, n = nums.size();
        unordered_map<int, int> mp;
        for(int r = 0; r < n; r++){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k - 1);
    }
};