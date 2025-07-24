class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;
        for(int i : nums){
            if(st.find(i - 1) != st.end()){
                continue;
            }

            int j = i;
            while(st.find(j) != st.end()){
                st.erase(j);
                j++;
            }

            ans = max(ans, j - i);
        }

        return ans;
    }
};