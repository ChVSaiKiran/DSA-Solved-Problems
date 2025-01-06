class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();

        int prefix[] = new int[n];
        int preCnt = 0, preSum = 0;
        for(int i = 0; i < n; i++){
            prefix[i] = preSum;
            preCnt += (boxes.charAt(i) == '1' ? 1 : 0);
            preSum += preCnt;
        }

        int suffix[] = new int[n];
        int sufCnt = 0, sufSum = 0;
        
        for(int i = n - 1; i >= 0; i--){
            suffix[i] = sufSum;
            sufCnt += (boxes.charAt(i) == '1' ? 1 : 0);
            sufSum += sufCnt;
        }

        int ans[] = new int[n];
        for(int i = 0; i < n; i++){
            ans[i] = prefix[i] + suffix[i];
        }

        return ans;
    }
}