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
                int l = top.second, r = i, len = 2;

                if(mp.count(l - 1)){
                    len += mp[l - 1];   mp.erase(l - 1);
                }

                if(mp.count(r - 1)){
                    len += mp[r - 1];   mp.erase(r - 1);
                }

                mp[r] = len;
                ans = max(ans, len);
            } else{
                stk.push({ch, i});
            }
        }

        return ans;
    }
};