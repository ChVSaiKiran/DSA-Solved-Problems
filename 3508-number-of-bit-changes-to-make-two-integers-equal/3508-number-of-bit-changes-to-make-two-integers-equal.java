class Solution {
    public int minChanges(int n, int k) {
        int cnt = 0;
        while(n >= k && k != 0){
            if((n & 1) != (k & 1)){
                if((n & 1) == 1){
                    cnt++;
                } else{
                    return -1;
                }
            }
            n >>= 1;
            k >>= 1;
        }

        while(n != 0){
            cnt += (n & 1);
            n >>= 1;
        }

        return n == k ? cnt : -1;
    }
}