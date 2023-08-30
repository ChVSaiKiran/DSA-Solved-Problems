class Solution {
    public int longestOnes(int[] nums, int k) {
        int cnt = 0, j = 0, ans = 0;
        for(int i = 0; i < nums.length; i++){
            cnt++;
            if(nums[i] == 0)
                k--;
            while(k < 0){
                if(nums[j] == 0)
                    k++;
                j++;
                cnt--;
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}