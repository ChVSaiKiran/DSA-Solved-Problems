class Solution {
public:
    void merge_sort(vector<int>& nums, int l, int h){
        if(l >= h){
            return;
        }
        vector<int> temp;
        int m = (l + h) / 2, i = l, j = m + 1;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, h);
        while(i <= m && j <= h){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            } else{
                temp.push_back(nums[j++]);
            }
        }
        while(i <= m){
            temp.push_back(nums[i++]);
        }
        while(j <= h){
            temp.push_back(nums[j++]);
        }
        int k = l;
        for(int i : temp){
            nums[k++] = i;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};