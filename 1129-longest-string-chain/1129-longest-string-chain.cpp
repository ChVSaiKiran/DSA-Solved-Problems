class Solution {
private: 
    bool f(string s, string t, int ind1, int ind2, bool flag){
        if(ind2 < 0){
            if(ind1 >= 0){
                return false;
            }
            return !flag;
        }

        if(ind1 < 0){
            return (ind2 == 0 && flag);
        }

        if(s[ind1] == t[ind2]){
            return f(s, t, ind1 - 1, ind2 - 1, flag);
        } 
        
        if(flag){
            return f(s, t, ind1, ind2 - 1, false);
        }
        
        return false;
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
                if((x - y) > 1){
                    break;
                }

                if((x - y == 1) && (dp[j] + 1 > dp[i]) && f(words[j], words[i], y - 1, x - 1, true)){
                    dp[i] = dp[j] + 1;
                }
            }
            len = max(len, dp[i]);
        }
        return len;
    }
};