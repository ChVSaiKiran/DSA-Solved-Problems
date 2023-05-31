class Solution {
    bool valid(string s, int lo, int hi){
        for(int i = lo, j = hi; i < j; i++, j--)
            if(s[i] != s[j])
                return false;
        return true;
    }
public:
    bool validPalindrome(string s) {
        for(int i = 0, j = s.length() - 1; i < j; i++, j--)
            if(s[i] != s[j])
                return valid(s, i + 1, j) || valid(s, i, j - 1);
        return true;
    }
};