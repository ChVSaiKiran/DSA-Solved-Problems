class Solution {
private:
    int fun(vector<int> &nums, vector<vector<int>>& queries, int k){
        int n = nums.size();
        vector<int> temp(n + 1, 0);
        for(int i = 0; i < k; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            temp[l] += val;  temp[r + 1] -= val;
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += temp[i];
            if(sum < nums[i]){
                return false;
            }
        }

        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 1, high = queries.size(), ans = -1, n = nums.size();
        for(int i : nums){
            n -= (i == 0);
        }

        if(n == 0){
            return 0;
        }
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(fun(nums, queries, mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};