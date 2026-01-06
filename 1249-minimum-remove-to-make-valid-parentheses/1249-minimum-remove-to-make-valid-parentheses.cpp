class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch != '(' && ch != ')'){
                continue;
            } else if(ch == '('){
                stk.push(i);
            } else if(!stk.empty() && s[stk.top()] == '('){
                stk.pop();
            } else{
                stk.push(i);
            }
        }

        vector<bool> temp(s.length(), true);
        while(!stk.empty()){
            temp[stk.top()] = false;    stk.pop();
        }

        string ans;
        for(int i = 0; i < s.length(); i++){
            if(temp[i]){
                ans += s[i];
            }
        }

        return ans;
    }
};