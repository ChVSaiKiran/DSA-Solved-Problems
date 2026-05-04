class NumArray {
private:
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        preSum.reserve(nums.size());
        for(int i : nums){
            preSum.emplace_back(i + (preSum.size() > 0 ? preSum.back() : 0));
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right] - (left > 0 ? preSum[left - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */