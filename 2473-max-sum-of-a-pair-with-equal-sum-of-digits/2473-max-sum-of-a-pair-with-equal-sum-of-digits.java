class Solution {
    private int sumOfDigits(int n){
        int sum = 0;
        while(n > 0){
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    public int maximumSum(int[] nums) {
        int ans = -1;
        HashMap<Integer, Integer> mp = new HashMap<>();

        for(int val : nums){
            int sum = sumOfDigits(val);
            if(mp.containsKey(sum)){
                ans = Math.max(ans, val + mp.get(sum));
            }
            mp.put(sum, Math.max(val, mp.getOrDefault(sum, 0)));
        }

        return ans;
    }
}