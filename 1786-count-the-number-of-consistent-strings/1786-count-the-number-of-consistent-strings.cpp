class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st(allowed.begin(), allowed.end());
        int cnt = 0;
        for(string s : words){
            int val = 1;
            for(char i : s){
                if(st.count(i) == 0){
                    val = 0;
                    break;
                }
            }
            cnt += val;
        }
        return cnt;
    }
};