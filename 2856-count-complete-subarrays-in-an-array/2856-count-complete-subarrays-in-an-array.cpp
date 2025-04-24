class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        set<int> st, s(nums.begin(), nums.end());
        

        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++){
            s.erase(nums[i]);  
            if(mp.find(nums[i]) != mp.end()){
                st.erase(mp[nums[i]]);
            }

            mp[nums[i]] = i;
            st.insert(i);

            if(s.size() == 0){
                ans += (*(st.begin()) + 1);
            }
        }

        return ans;
    }
};