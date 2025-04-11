class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++){
            if((i < 10) || (i >= 100 && i <= 999) || i == 1e4)  continue;
            if(i < 100){
                cnt += (i % 11 == 0);
            } else{
                int sum1 = (i % 10) + (i / 10) % 10;
                int sum2 = (i / 100) % 10 + (i / 1000);
                cnt += (sum1 == sum2);
            }
        }
        return cnt;
    }
};