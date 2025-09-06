class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for(int i = 0; i < s.length(); i++){
            if(!(s[i] == '(' || s[i] == ')'))    continue;
            if(stk.empty() || s[i] == '(')  stk.push(i);
            else if(s[stk.top()] == '(')    stk.pop();
            else                            stk.push(i);
        }

        unordered_set<int> st;
        while(!stk.empty()) st.insert(stk.top()), stk.pop();

        string ans;
        for(int i = 0; i < s.length(); i++){
            if(st.count(i)) continue;
            ans += s[i];
        }

        return ans;
    }
};