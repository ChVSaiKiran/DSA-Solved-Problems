class Solution {
public:
    int getIndex(vector<int> &nums, int idx){
        int val = 1e9, ansIdx = -1;
        for(int i = idx + 1; i < nums.size(); i++){
            if(nums[i] > nums[idx] && val > nums[i]){
                val = nums[i];
                ansIdx = i;
            }
        }
        return ansIdx;
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i;
        for(i = n - 1; i > 0; i--){
            if(nums[i - 1] < nums[i]){
                break;
            }
        }

        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }

        int idx1 = i - 1;
        int idx2 = getIndex(nums, idx1);
        swap(nums[idx1], nums[idx2]);

        sort(nums.begin() + i, nums.end());
    }
};