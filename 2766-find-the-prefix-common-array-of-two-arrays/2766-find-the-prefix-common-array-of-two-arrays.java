class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length, ans[] = new int[n], cnt = 0;
        int freq1[] = new int[n + 1], freq2[] = new int[n + 1];

        for(int i = 0; i < n; i++){
            freq1[A[i]] = 1;
            freq2[B[i]] = 1;

            if(freq1[B[i]] == 1){
                cnt++;
            }

            if(freq2[A[i]] == 1){
                cnt++;
            }

            if(A[i] == B[i]){
                cnt--;
            }

            ans[i] = cnt;
        }

        return ans;
    }
}