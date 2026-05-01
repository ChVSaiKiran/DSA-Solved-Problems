class Solution {
private:
    int f(vector<int>& nums, int k){
        int n = nums.size(), l = 0, cnt = 0, res = 0;
        unordered_map<int, int> mp;
        for(int r = 0; r < n; r++){
            mp[nums[r]]++;

            if(mp[nums[r]] == 1){
                cnt++;
            }

            while(cnt > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    cnt--;
                }
                l++;
            }
            
            res += (r - l + 1);
        }

        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k - 1);
    }
};