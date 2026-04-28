class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1, m = n - 1;
                long val = target;  val -= nums[i]; val -= nums[j];
                while(k < m){
                    long sum = nums[k]; sum += nums[m];
                    if(sum == val){
                        while(k < m && nums[k] == nums[k + 1]){
                            k++;
                        }

                        while(k < m && nums[m] == nums[m - 1]){
                            m--;
                        }

                        ans.push_back({nums[i], nums[j], nums[k], nums[m]});
                        k++, m--;
                    } else{
                        sum > val ? m-- : k++;
                    }
                }
            }
        }

        return ans;
    }
};