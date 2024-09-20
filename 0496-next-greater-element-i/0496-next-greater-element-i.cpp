class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        stack<int> s;
        vector<int> temp(m);
        unordered_map<int, int> mp;

        for(int i = m - 1; i >= 0; i--){
            int val = nums2[i];
            while(!s.empty() && val >= s.top()){
                s.pop();
            }

            if(s.empty()){
                temp[i] = -1;
            } else{
                temp[i] = s.top();
            }

            s.push(val);
            mp[val] = i;
        }

        vector<int> ans;
        ans.reserve(n);

        for(int i : nums1){
            ans.push_back(temp[mp[i]]);
        }

        return ans;
    }
};