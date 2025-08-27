class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            bool lt = m > 0 ? nums[m] > nums[m - 1] : true;
            bool rt = m < n - 1 ? nums[m] > nums[m + 1] : true;
            if(lt && rt)    return m;
            if(lt)  l = m + 1;
            else    r = m - 1;
        }
        return -1;
    }
};