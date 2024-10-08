class Solution {
public:
    int minSwaps(string s) {
        stack<char> d;
        for(char i : s){
            if(d.empty() || i == '['){
                d.push(i);
            } else if(d.top() == '['){
                d.pop();
            } else{
                d.push(i);
            }
        }

        if(d.empty()){
            return 0;
        }

        int pairs = d.size() / 2;

        return (pairs / 2) + (pairs % 2);
    }
};