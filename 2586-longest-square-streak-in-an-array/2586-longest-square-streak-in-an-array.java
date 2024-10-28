class Solution {
    public int longestSquareStreak(int[] nums) {
        int n = (int)(1e5 + 1);
        boolean temp[] = new boolean[n];
        for(int i : nums){
            temp[i] = true;
        }
        
        int ans = -1;
        for(long i = 1; i * i <= n; i++){
            if(temp[(int)i]){
                int len = 1;
                for(long j = i * i; j <= n; j = j * j){
                    if(temp[(int)j] == false){
                        break;
                    }
                    len++;
                }
                if(len >= 2){
                    ans = Math.max(ans, len);
                }
            }
        }

        return ans;
    }
}