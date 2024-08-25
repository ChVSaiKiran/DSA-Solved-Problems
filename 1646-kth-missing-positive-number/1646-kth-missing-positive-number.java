class Solution {
    public int findKthPositive(int[] arr, int k) {
        int low = 0, high = arr.length - 1;
        if(k < arr[low]){
            return k;
        }
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] - (mid + 1) < k){
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        int cntMissTill = arr[high] - (high + 1), ans = arr[high];
        if(k > cntMissTill){
            ans += (k - cntMissTill);
        } else{
            ans -= (cntMissTill - k + 1);
        }
        // System.out.println("High: " + high + " Miss Till: " + cntMissTill);
        return ans;
    }
}