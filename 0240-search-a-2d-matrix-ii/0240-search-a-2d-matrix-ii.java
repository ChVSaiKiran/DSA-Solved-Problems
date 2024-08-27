class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length, m = matrix[0].length;
        int i = 0, j = m - 1;
        while(i >= 0 && i < n && j >= 0 && j < m){
            if(target == matrix[i][j]){
                return true;
            }
            else if(target > matrix[i][j]){
                i++;
            } else{
                j--;
            }
        }
        return false;
    }
}