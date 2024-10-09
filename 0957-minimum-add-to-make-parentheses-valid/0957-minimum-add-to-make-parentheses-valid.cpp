class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(char i : s){
            if(stk.empty() || i == '('){
                stk.push(i);
            } else if(stk.top() == '('){
                stk.pop();
            } else{
                stk.push(i);
            }
        }

        return stk.size();
    }
};