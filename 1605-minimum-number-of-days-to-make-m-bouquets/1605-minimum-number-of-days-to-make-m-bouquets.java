class Solution {
    private boolean f(int[] bloomDay, int day, int m, int k){
        int cnt = 0;
        for(int i : bloomDay){
            if(i <= day){
                cnt++;
                if(cnt == k){
                    m--;
                    cnt = 0;
                    if(m == 0){
                        return true;
                    }
                }
            } else{
                cnt = 0;
            }
        }
        return false;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        int ans = -1, low = 1;
        int high = Arrays.stream(bloomDay).max().getAsInt();
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(f(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return ans;
    }
}