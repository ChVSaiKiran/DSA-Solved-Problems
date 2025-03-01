class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long sum = accumulate(nums.begin(), nums.end(), 0l);
        int n = nums.size(), k = sum % p, ans = n;

        if(k == 0){
            return 0;
        }
        
        long psum = 0;
        unordered_map<int,int> mp{{0, -1}};

        for(int i = 0; i < n; i++){
            psum += nums[i];
            int r = psum % p;
            int d = (r - k + p) % p; 
            if(mp.count(d)){
                ans = min(ans, i - mp[d]);
            }
            mp[r] = i;
        }

        return ans == n ? -1 : ans;
    }
};