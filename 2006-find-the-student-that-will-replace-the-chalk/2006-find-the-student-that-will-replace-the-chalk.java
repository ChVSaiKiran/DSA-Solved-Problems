class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        int n = chalk.length;
        long sum = 0;
        long temp[] = new long[n];
        for(int i = 0; i < n; i++){
            sum += chalk[i];
            temp[i] += sum;
        }

        long tar = k % sum;
        int low = 0, high = n - 1, ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(temp[mid] == tar){
                return mid + 1;
            } else if(temp[mid] < tar){
                low = mid + 1;
            } else{
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
}