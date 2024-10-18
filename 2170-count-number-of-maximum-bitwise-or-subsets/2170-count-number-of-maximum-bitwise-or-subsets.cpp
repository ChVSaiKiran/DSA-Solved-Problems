class Solution {
private:
    map<long, int> mp;
    void fun(vector<int> &nums, int i, long val){
        if(i < 0){
            return;
        }
        fun(nums, i - 1, val);
        fun(nums, i - 1, nums[i] | val);
        mp[nums[i] | val]++;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        fun(nums, nums.size() - 1, 0);
        return mp.rbegin() -> second;
    }
};