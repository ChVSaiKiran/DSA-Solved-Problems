class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> st;

        for(int i = 0; i < k; i++)
            st.insert(nums[i]);

        vector<int> ans;
        ans.reserve(n - k + 1);

        for(int i = k; i < n; i++){
            ans.push_back(*st.rbegin());
            st.erase(st.lower_bound(nums[i - k]));
            st.insert(nums[i]);
        }

        ans.push_back(*st.rbegin());
        return ans;
    }
};