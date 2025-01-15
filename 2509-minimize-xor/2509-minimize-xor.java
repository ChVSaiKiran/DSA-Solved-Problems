class Solution {
    private int noOfSetBits(int num){
        int cnt = 0;
        while(num != 0){
            if((num & 1) == 1){
                cnt++;
            }
            num >>= 1;
        }
        return cnt;
    }

    private int noOfBits(int num){
        int cnt = 0;
        while(num != 0){
            cnt++; num >>= 1;
        }
        return cnt;
    }

    public int minimizeXor(int num1, int num2) {
        int setA = noOfSetBits(num1);
        int setB = noOfSetBits(num2);
        
        if(setA == setB){
            return num1;
        } else if(setA < setB){
            int cnt = 0, ans = num1;
            int diff = setB - setA;
            while(num1 != 0 && diff != 0){
                if((num1 & 1) == 0){
                    ans = ans ^ (1 << cnt);
                    diff--;
                }
                num1 >>= 1;
                cnt++;
            }
            
            while(diff != 0){
                ans = ans ^ (1 << cnt);
                cnt++; diff--;
            }

            return ans;

        } else{
            int ans = 0, n = noOfBits(num1);
            int diff = setB;
            for(int i = n - 1; i >= 0; i--){
                if(diff == 0){
                    break;
                }

                if((num1 & (1 << i)) != 0){
                    ans = ans ^ (1 << i);
                    diff--;
                }
            }
            return ans;
        }
    }
}