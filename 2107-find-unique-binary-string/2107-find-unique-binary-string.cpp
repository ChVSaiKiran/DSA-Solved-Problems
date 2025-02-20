class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(string s : nums){
            int val = 0, pow2 = pow(2, n - 1);
            for(int i = 0; i < n; i++){
                val += (s[i] == '1' ? pow2 : 0);
                pow2 /= 2;
            }
            st.insert(val);
        }

        int val = 0;
        while(st.count(val)){
            val++;
        }

        string ans(n, '0');
        for(int i = n - 1; (i >= 0 && val > 0); i--){
            ans[i] = val % 2 ? '1' : '0';
            val /= 2;
        }

        return ans;
    }
};