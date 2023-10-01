class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lpro = 1, rpro = 1, n = nums.size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            if(lpro == 0)
                lpro = 1;
            if(rpro == 0)
                rpro = 1;
            lpro *= nums[i];
            rpro *= nums[n - 1 - i];
            ans = max(ans, max(lpro, rpro));
        }
        return ans;
    }
};