class Solution {
    int power2(int n){
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        return n ^ (n>>1);
    }
public:
    int minOperations(int n) {
        if( (n & (n - 1)) == 0)
            return 1;
        int low = power2(n), high = low * 2;
        return 1  + minOperations(min(n -low, high - n));
    }
};