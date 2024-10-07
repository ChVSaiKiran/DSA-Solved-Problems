class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for(char i : s){
            if(stk.empty()){
                stk.push(i);
            } else if(stk.top() == 'A' && i == 'B'){
                stk.pop();
            } else if(stk.top() == 'C' && i == 'D'){
                stk.pop();
            } else{
                stk.push(i);
            }
        }
        return stk.size();
    }
};