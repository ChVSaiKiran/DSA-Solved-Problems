class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j = 0, n = s.length(), ans = 0;
        vector<bool> vis(256, false);
        for(int i = 0; i < n; i++){
            while(vis[s[i]]){
                vis[s[j++]] = false;
            }
            vis[s[i]] = true;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};