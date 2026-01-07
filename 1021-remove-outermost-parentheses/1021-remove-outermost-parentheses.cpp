class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<int> stk;
        for(int r = 0; r < s.length(); r++){
            if(s[r] == '('){
                stk.push(r);
            } else if(!stk.empty()) {
                int l = stk.top();  stk.pop();
                if(stk.empty()){
                    ans += s.substr(l + 1, r - l - 1); 
                }
            }
        }

        return ans;
    }
};