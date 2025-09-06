class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(char i : str){
            if(i == '(' || i == '[' || i == '{'){
                s.push(i);
            } else if(s.empty()){
                return false;
            } else if(s.top() == '(' && i == ')'){
                s.pop();
            } else if(s.top() == '[' && i == ']'){
                s.pop();
            } else if(s.top() == '{' && i == '}'){
                s.pop(); 
            } else{
                return false;
            }
        }

        return s.empty();
    }
};