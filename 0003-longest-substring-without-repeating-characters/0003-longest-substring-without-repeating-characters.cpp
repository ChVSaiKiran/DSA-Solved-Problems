class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j = 0, n = s.size(), ans = 0;
        vector<bool> temp(256, false);
        for(int i = 0; i < n; i++){
            while(temp[s[i]]){
                temp[s[j++]] = false;
            }
            ans = max(ans, i - j + 1);
            temp[s[i]] = true;
        }
        return ans;
    }
};