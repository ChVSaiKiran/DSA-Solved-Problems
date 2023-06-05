class Solution {
public:
    bool count(vector<int> nums, int dis, int k){
        int j = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            while(j < nums.size() && nums[j] - nums[i] <= dis)
                j++;
            cnt += (j - i - 1);
        }
        return cnt >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int min_diff = INT_MAX, max_diff = nums[n - 1] - nums[0];
        for(int i = 0; i < n - 1; i++)
            min_diff = min(min_diff, nums[i + 1] - nums[i]);
        while(min_diff < max_diff){
            int mid = (min_diff + max_diff) / 2;
            if(count(nums,mid,k))
                max_diff = mid;
            else
                min_diff = mid + 1;
        }
        return min_diff;
    }
};