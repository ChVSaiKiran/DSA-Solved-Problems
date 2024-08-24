class Solution {
    private boolean f(int[] piles, int BananasPerHour, int h){
        int timeToComplete = 0;
        for(int i : piles){
            timeToComplete += ((i + BananasPerHour - 1) / BananasPerHour);
            if(timeToComplete > h){
                return false;
            }
        }
        return true;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int low = 1, high = Arrays.stream(piles).max().getAsInt(), ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(f(piles, mid, h)){
                ans = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }

        return ans;
    }
}