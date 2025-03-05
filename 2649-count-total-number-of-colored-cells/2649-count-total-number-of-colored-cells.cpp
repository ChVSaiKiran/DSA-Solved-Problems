class Solution {
public:
    long long coloredCells(int n) {
        long long ans = n - 1;
        ans *= (n - 1);
        ans *= 2;
        ans += (2 * n - 1);
        return ans;
    }
};