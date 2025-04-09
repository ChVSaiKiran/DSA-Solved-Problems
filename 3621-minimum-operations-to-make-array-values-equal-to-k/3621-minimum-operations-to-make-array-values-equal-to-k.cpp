class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int i : nums){
            if(i < k){
                return -1;
            }
            
            if(i > k){
                st.insert(i);
            }
        }
        return st.size();
    }
};