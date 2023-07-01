class Solution {
public:
    double myPow(double x, int n) {
        bool f1 = false, f2 = false;
        long p = n;
        if(p < 0)
            p *= -1, f2 = true;
        if(x < 0)
            x *= -1, f1 = (p % 2 == 1);
        double ans = 1;
        while(p){
            if(p & 1)
                ans *= x;
            x *= x;
            p >>= 1;
        }
        if(f2)
            ans = 1 / ans;
        if(f1)
            ans *= -1;
        return ans;
    }
};