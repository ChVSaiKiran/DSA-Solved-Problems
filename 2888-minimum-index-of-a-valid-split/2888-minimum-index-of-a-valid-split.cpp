class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> suffix;
        for(int i : nums) suffix[i]++;

        int n = nums.size();
        unordered_map<int, int> prefix;
        for(int i = 0; i < n; i++){
            int val = nums[i];
            prefix[val]++;  suffix[val]--;
            if(prefix[val] > (i + 1) / 2 && suffix[val] > (n - 1 - i) / 2){
                return i;
            }
        }

        return -1;
    }
};