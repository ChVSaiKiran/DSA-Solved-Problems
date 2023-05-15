class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0, n = columnTitle.length();
        long long temp = 1;
        for(int i = n - 1; i > -1; i--){
            ans += temp * (columnTitle[i] - 'A' + 1);
            temp *= 26;
        }
        return ans;
    }
};