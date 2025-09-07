class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> stk;
        vector<int> mp(s.length() + 1, 0);
        for(int i = 0; i < s.length(); i++){
            if(stk.empty() || s[i] == '('){
                stk.push(i);
            } else if(s[stk.top()] == '('){
                int sIdx = stk.top();   stk.pop();
                int len = i - sIdx + 1;
                ans = max(ans, len + mp[sIdx]);
                mp[i + 1] = len + mp[sIdx];
            } else{
                stk.push(i);
            }
        }
        return ans;
    }
};