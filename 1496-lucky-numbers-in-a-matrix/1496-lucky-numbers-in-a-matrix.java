class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int row[] = new int[n], col[] = new int[m];
        
        Arrays.fill(row, Integer.MAX_VALUE);
        Arrays.fill(col, Integer.MIN_VALUE);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                row[i] = Math.min(row[i], matrix[i][j]);
            }
        }

        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                col[j] = Math.max(col[j], matrix[i][j]);
            }
        }

        List<Integer> ans = new ArrayList<>();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row[i] == col[j]){
                    ans.add(row[i]);
                }
            }
        }

        return ans;
    }
}