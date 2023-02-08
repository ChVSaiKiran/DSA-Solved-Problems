class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <1 || ((n & (n-1)) != 0))
            return false;
        if(n == 1)
            return true;
        int co = 0;
        while(n){
            co++;
            n>>=1;
        }
        return co%2 != 0;
    }
};