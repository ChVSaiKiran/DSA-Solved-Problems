class Solution {
public:
    double myPow(double x, int n) {
        bool flag = false;
        long p = n;
        if(p < 0)
            p *= -1, flag = true;
        double ans = 1;
        while(p){
            if(p & 1)
                ans *= x;
            x *= x;
            p >>= 1;
        }
        if(flag)
            ans = 1 / ans;
        return ans;
    }
};