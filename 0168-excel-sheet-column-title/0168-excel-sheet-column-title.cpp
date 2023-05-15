class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n > 0){
            int rem = (n - 1) % 26;
            ans = (char)('A' + rem) + ans;
            n = (n - 1) / 26;
        }
        return ans;
    }
};