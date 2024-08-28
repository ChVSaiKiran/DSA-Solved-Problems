class Solution {
    private int f(int[] arr, int n){
        int idx = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] > arr[idx]){
                idx = i;
            }
        }
        return idx;
    }
    public int[] findPeakGrid(int[][] mat) {
        int ans[] = new int[2];

        int n = mat.length, m = mat[0].length;
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int maxIdx = f(mat[mid], m);
            int prevRowEle = -1;
            int currRowEle = mat[mid][maxIdx]; 
            int nextRowEle = -1;
            if(mid != 0)  prevRowEle = mat[mid - 1][maxIdx];
            if(mid != n - 1)  nextRowEle = mat[mid + 1][maxIdx];
            if(prevRowEle < currRowEle && currRowEle > nextRowEle){
                ans[0] = mid;
                ans[1] = maxIdx;
                return ans;
            } else if(prevRowEle > currRowEle){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return ans;
    }
}