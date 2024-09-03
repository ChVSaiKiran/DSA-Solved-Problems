class Solution {
private: 
    bool check(string &s, string &t){
        if(s.size() != t.size() + 1){
            return false;
        }

        int i = 0, j = 0;
        while(i < s.size()){
            if(j < t.size() && s[i] == t[j]){
                j++;
            }
            i++;
        }

        return i == s.size() && j == t.size();
    }
    
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(), len = 1;
        sort(words.begin(), words.end(), [](string a, string b){
            return a.length() < b.length();
        });

        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            int x = words[i].size();
            for(int j = i - 1; j >= 0; j--){
                int y = words[j].size();
                if((dp[j] + 1 > dp[i]) && check(words[i], words[j])){
                    dp[i] = dp[j] + 1;
                }
            }
            len = max(len, dp[i]);
        }
        return len;
    }
};