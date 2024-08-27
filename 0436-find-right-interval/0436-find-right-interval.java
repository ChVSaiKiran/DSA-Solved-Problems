class Solution {
    private int f(int[][] arr, int target){
        int n = arr.length;
        int low = 0, high = n - 1, ansIdx = n;
        while(low <= high){
            int m = low + (high - low) / 2;
            if(target <= arr[m][0]){
                ansIdx = Math.min(ansIdx, arr[m][2]);
                high = m - 1;
            } else{
                low = m + 1;
            }
        }

        return ansIdx == n ? -1 : ansIdx;
    }

    public int[] findRightInterval(int[][] arr) {
        int n = arr.length;
        int temp[][] = new int[n][3];
        for(int i = 0; i < n; i++){
            temp[i][0] = arr[i][0];
            temp[i][1] = arr[i][1];
            temp[i][2] = i;
        }

        Arrays.sort(temp, (a, b) -> Integer.compare(a[0], b[0]));
        int[] ans = new int[n];

        for(int i = 0; i < n; i++){
            int orgIdx = temp[i][2];
            ans[orgIdx] = f(temp, temp[i][1]);
        }

        return ans;
    }
}