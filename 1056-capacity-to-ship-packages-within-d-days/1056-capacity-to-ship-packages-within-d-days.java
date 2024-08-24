class Solution {
    private boolean f(int[] weights, int days, int maxCapacity){
        int currWeight = 0, noOfDays = 0;
        for(int i : weights){
            currWeight += i;
            if(currWeight >= maxCapacity){
                noOfDays++;
                currWeight = (currWeight == maxCapacity) ? 0 : i;
            }
        }
        noOfDays += (currWeight != 0 ? 1 : 0);
        return noOfDays <= days;
    }
    public int shipWithinDays(int[] weights, int days) {
        int low = Arrays.stream(weights).max().getAsInt();
        int high = Arrays.stream(weights).sum(), ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(f(weights, days, mid)){
                ans = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return ans;
    }
}