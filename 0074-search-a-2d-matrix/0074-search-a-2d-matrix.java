class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length, m = matrix[0].length;
        int low = 0, high = n * m - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int x = mid / m, y = mid % m;
            if(matrix[x][y] == target){
                return true;
            } else if(matrix[x][y] > target){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return false;
    }
}