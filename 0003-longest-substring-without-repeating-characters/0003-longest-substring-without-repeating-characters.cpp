class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0, cnt = 0, i = 0;
        vector<bool> arr(256, false);
        for(int j = 0; j < n; j++){
            while(arr[s[j]]){
                arr[s[i]] = false;
                i++;
            }
            arr[s[j]] = true;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};