class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == t)
            return true;
        int i = 0, n = s.length();
        for(char ch:t){
            if(ch == s[i])
                i++;
            if(i == n)
                return true;
        }
        return false;
    }
};