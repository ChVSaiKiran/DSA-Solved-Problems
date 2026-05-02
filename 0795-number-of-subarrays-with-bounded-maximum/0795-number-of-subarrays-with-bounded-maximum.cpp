class Solution {
private:
    int f1(vector<int>& nums, int k){
        int cnt = 0, l = 0, n = nums.size();
        for(int r = 0; r < n; r++){
            if(nums[r] > k){
                l = r + 1;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }

    int f2(vector<int>& nums, int k){
        int cnt = 0, l = 0, n = nums.size();
        for(int r = 0; r < n; r++){
            if(nums[r] >= k){
                l = r + 1;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return f1(nums, right) - f2(nums, left);
    }
};