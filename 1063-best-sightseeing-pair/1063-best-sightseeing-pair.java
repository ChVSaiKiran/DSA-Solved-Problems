class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int n = values.length, ans = Integer.MIN_VALUE;
        int temp[] = new int[1001];
        Arrays.fill(temp, -1);

        for(int i = 0; i < n; i++){
            int val = values[i];
            for(int j = 1; j <= 1000; j++){
                if(temp[j] != -1){
                    ans = Math.max(ans, (val + j) + temp[j] - i);
                }
            }
            temp[val] = i;
        }

        return ans;
    }
}