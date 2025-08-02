class Solution {
    bool isValid(string s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++, j--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        for(int i = 0, j = s.length() - 1; i < j; i++, j--){
            if(s[i] != s[j]){
                return isValid(s, i + 1, j) || isValid(s, i, j - 1);
            }
        }
        return true;
    }
};