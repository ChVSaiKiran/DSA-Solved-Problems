class Solution {
public:
    int findComplement(int num) {
        int ans = num, pow2 = 1;
        while(num){
            if(num & 1){
                ans &= (~pow2);
            } else{
                ans |= pow2;
            }
            num >>= 1, pow2 <<= 1;
        }
        return ans;
    }
};