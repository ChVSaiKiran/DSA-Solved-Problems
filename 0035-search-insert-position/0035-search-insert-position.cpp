class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Method 1
        // Smallest number greater than target
        int low = 0, high = nums.size() - 1, ind = high + 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] > target){
                ind = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return ind;

        // Method 2
        // largest number less than target and add + 1
        // int searchInsert(vector<int>& nums, int target) {
        // int low = 0, high = nums.size() - 1, ind = -1;
        // while(low <= high){
        //     int mid = low + (high - low)/2;
        //     if(nums[mid] == target){
        //         return mid;
        //     } else if(nums[mid] > target){
        //         high = mid - 1;
        //     } else{
        //         ind = mid;
        //         low = mid + 1;
        //     }
        // }
        // return ind + 1;
        // }
    }
};