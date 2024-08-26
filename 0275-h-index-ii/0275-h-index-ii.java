class Solution {
    private boolean f(int[] citations, int h){
        int cnt = 0;
        for(int i : citations){
            if(i >= h){
                cnt++;
            }
        }
        return cnt >= h;
    }

    public int hIndex(int[] citations) {
        int low = 1, high = citations[citations.length - 1], ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(f(citations, mid)){
                ans = Math.max(ans, mid);
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }

        return ans;
    }
}