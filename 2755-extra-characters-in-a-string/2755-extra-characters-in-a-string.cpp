class Solution {
private:
    int f(string s, int i, string curr, unordered_set<string> &st, map<pair<int, string>, int> &dp){

        int len = curr.length();
        if(i == s.length()){
            if(st.find(curr) == st.end()){
                return len;
            }
            return 0;
        }

        pair<int, string> key = make_pair(i, curr);

        if(dp.find(key) != dp.end()){
            return dp[key];
        }

        int notPick = f(s, i + 1, string(1, s[i]), st, dp);
        int pick = f(s, i + 1, curr + s[i], st, dp);

        if(st.find(curr) == st.end()){
            notPick += len;
        }

        return dp[key] = min(notPick, pick);
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        map<pair<int, string>, int> dp;
        
        return f(s, 0, "", st, dp);
    }
};