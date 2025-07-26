class Solution {
private:
    int lb(vector<int> &nums, int l, int r, long val){
        int ans = r + 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(nums[m] > val){
                ans = m;
                r = m - 1;
            } else{
                l = m + 1;
            }
        }
        return ans;
    }

    int fun(vector<int> &nums, int s, int e){
        if(s >= e){
            return 0;
        }

        int m = (s + e) / 2, cnt = 0;
        cnt += fun(nums, s, m);
        cnt += fun(nums, m + 1, e);

        int pIdx = s;
        for(int i = m + 1; i <= e; i++){
            pIdx = lb(nums, pIdx, m, 2l * nums[i]);
            cnt += (m + 1 - pIdx);
        }

        inplace_merge(nums.begin() + s, nums.begin() + m + 1, nums.begin() + e + 1);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return fun(nums, 0, nums.size() - 1);
    }
};