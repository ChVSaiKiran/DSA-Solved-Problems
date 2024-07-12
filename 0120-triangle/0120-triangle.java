class Solution {
    public int recursive(List<List<Integer>> arr, int i, int j, List<List<Integer>> dp){
        if(i == arr.size() - 1){
            dp.get(i).set(j, arr.get(i).get(j));
            return dp.get(i).get(j);
        }

        if(dp.get(i).get(j) != -1){
            return dp.get(i).get(j);
        }

        int lt = recursive(arr, i + 1, j, dp), rt = recursive(arr, i + 1, j + 1, dp);
        dp.get(i).set(j, Math.min(lt, rt) + arr.get(i).get(j));

        return dp.get(i).get(j);
    }
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size(), m = triangle.get(n - 1).size();
        int prev[] = new int[m];
        
        for(int j = 0; j < m; j++){
            prev[j] = triangle.get(n - 1).get(j);
        }

        for(int i = n - 2; i >= 0; i--){
            int curr[] = new int[m];
            for(int j = 0; j <= i; j++){
                int lt = prev[j], rt = prev[j + 1];
                curr[j] = Math.min(lt, rt) + triangle.get(i).get(j);
            }
            prev = curr;
        }

        return prev[0];
    }
}