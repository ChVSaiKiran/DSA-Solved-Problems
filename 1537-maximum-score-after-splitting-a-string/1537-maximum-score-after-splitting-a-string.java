class Solution {
    public int maxScore(String s) {
        int n = s.length(), temp[] = new int[n], ones = 0;
        for(int i = n - 1; i >= 0; i--){
            ones += (s.charAt(i) == '1') ? 1 : 0;
            temp[i] = ones;
        }

        int ans = 0, zeros = 0;;
        for(int i = 0; i < n - 1; i++){
            zeros += (s.charAt(i) == '0') ? 1 : 0;
            ans = Math.max(ans, zeros + temp[i + 1]);
        }

        return ans;
    }
}