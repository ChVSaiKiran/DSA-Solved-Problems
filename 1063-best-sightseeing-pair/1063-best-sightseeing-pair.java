class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int n = values.length, ans = 0, maxVal = values[0];
        
        for(int i = 1; i < n; i++){
            ans = Math.max(ans, maxVal + (values[i] - i));
            maxVal = Math.max(maxVal, values[i] + i);
        }

        return ans;
    }
}