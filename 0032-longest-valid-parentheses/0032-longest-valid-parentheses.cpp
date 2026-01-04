class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        unordered_map<int, int> mp;
        stack<pair<char, int>> stk;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == '('){
                stk.push({ch, i});
            } else if(stk.size() != 0 && stk.top().first == '('){
                pair<char, int> top = stk.top(); stk.pop();
                int l = top.second, r = i;

                int l1 = mp[l - 1], l2 = mp[r - 1];
                int len = l1 + l2 + 2;  ans = max(ans, len);
                mp[r] = len;
            } else{
                stk.push({ch, i});
            }
        }

        return ans;
    }
};