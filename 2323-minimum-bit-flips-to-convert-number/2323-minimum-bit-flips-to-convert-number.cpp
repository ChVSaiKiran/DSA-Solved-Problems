class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xr = start ^ goal, cnt = 0;
        while(xr > 0){
            cnt += (xr & 1);
            xr >>= 1;
        }
        return cnt;
    }
};