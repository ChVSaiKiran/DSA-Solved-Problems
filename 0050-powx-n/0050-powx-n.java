class Solution {
    public double myPow(double x, int n) {
        double ans = 1;
        double x1 = x ;
        int n1 = 1;
        long p = n;
        if(n < 0){
            p *= -1;
            n1 = -1;
        }
       for(int i = 0;i <= (int)(Math.log(p) / Math.log(2));i++){
                if(((1<<i)&p) != 0){
                    ans = (ans * x1) % 1000000007;
                }
                x1 = (x1 *x1) % 1000000007;
            }
            if(n1 < 0){
                return 1/ans;
            }
            
            return ans;
    }
}