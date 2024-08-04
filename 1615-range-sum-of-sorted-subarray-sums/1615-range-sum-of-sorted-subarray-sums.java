class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        int k = n, temp[] = new int[n * (n + 1)/2];
        temp[0] = nums[0];

        for(int i = 1; i < n; i++){
            temp[i] = temp[i - 1] + nums[i];
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                temp[k++] = temp[j] - temp[i];
            }
        }

        Arrays.sort(temp);

        int sum = 0, mod = (int)(1e9 + 7);
        for(int i = left - 1; i < right; i++){
            sum = (sum + temp[i]) % mod;
        }
        
        return sum;
    }
}