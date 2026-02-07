class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(256, false);

        int j = 0, ans = 0;
        for(int i = 0; i < s.length(); i++){
            while(vis[s[i]]){
                vis[s[j++]] = false;
            }
            vis[s[i]] = true;
            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};