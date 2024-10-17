class Solution {
public:
    int maximumSwap(int num) {
        int ans = num;
        int prev = num % 10, place = 1;
        int temp = num / 10, pow10 = 10;
        while(temp > 0){
            int r = temp % 10;
            if(prev >= r){
                int val = num - (prev * place) + (place * r) + ((prev - r) * pow10);
                ans = max(ans, val); 
            } else{
                prev = r;
                place = pow10;
            }
            pow10 *= 10;
            temp /= 10;
        }
        return ans;
    }
};