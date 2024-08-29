class Solution {
    private int f(int arr[]){
        int low = 0, high = arr.length - 1, idx = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] >= 0){
                idx = mid;
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        return (idx + 1);
    }
    public int countNegatives(int[][] grid) {
        int ans = 0, m = grid[0].length;
        for(int row[] : grid){
            ans += (m - f(row));
        }
        return ans;
    }
}