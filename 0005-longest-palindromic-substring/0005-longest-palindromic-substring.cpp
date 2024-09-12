class Solution {
private:
    int f(string &s, int i, int j, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }

        if(i == j){
            return dp[i][j] = 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j]){
           return dp[i][j] = 2 + f(s, i + 1, j - 1, dp); 
        }

        return dp[i][j] = -1e9;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length(), maxLen = 0, idx = -1;
        vector<vector<int>> dp(n, vector<int> (n, -1));

        // Memoization Approach
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         int len = f(s, i, j, dp);
        //         if(len > maxLen){
        //             idx = i;
        //             maxLen = len;
        //         }
        //     }
        // }

        // Tabulation Approach
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(i > j){
                    dp[i][j] = 0;
                } else if(i == j){
                    dp[i][j] = 1;
                } else if(s[i] == s[j]){
                    dp[i][j] = 2;
                    if(i + 1 < n && j - 1 >= 0){
                        dp[i][j] += dp[i + 1][j - 1];
                    }
                } else{
                    dp[i][j] = -1e9;
                }

                if(maxLen < dp[i][j]){
                    maxLen = dp[i][j];
                    idx = i;
                }
            }
        }

        return s.substr(idx, maxLen);
    }
};