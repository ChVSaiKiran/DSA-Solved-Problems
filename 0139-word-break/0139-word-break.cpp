class Solution {
public:
    // Memoization
    int f(string s, int i, unordered_set<string> &st, vector<int> &dp){
        if(i >= s.length()){
            return 1;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }

        for(int len = 1; len <= s.length(); len++){
            string t = s.substr(i, len);
            if(st.count(t) && f(s, i + len, st, dp)){
                return 1;
            }
        }

        return 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.length();

        // vector<int> dp(n, -1);
        // return f(s, 0, st, dp);

        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--){
            for(int len = 1; len <= s.length() - i; len++){
                string t = s.substr(i, len);
                if(st.count(t) && dp[i + len]){
                    dp[i] = dp[i + len];
                    break;
                }
            }
        }

        return dp[0];
    }
};