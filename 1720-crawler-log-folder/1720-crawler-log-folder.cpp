class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for(string s : logs){
            if(s == "./"){
                continue;
            } else if(s == "../"){
                if(level > 0){
                    level--;
                }
            } else {
                level++;
            }
        }
        return abs(level);
    }
};