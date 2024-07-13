class Solution {
    private int fun(int[] nums, int ind, int target, int dp[][]){
        if(target == 0){
            return dp[ind][target] = 1;
        }

        if(ind == 0){
            return dp[0][target] = (nums[0] == target ? 1 : 0);
        }

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }

        int notTake = fun(nums, ind - 1, target, dp), Take = 0;

        if(target >= nums[ind]){
            Take = fun(nums, ind - 1, target - nums[ind], dp);
        }

        return dp[ind][target] = notTake | Take;
    }

    public boolean canPartition(int[] nums) {
        int sum = Arrays.stream(nums).sum(), n = nums.length;
        if(sum % 2 == 1 || n < 2){
            return false;
        }
        int target = sum / 2;
        boolean prev[] = new boolean[target + 1];

        prev[0] = true;
        
        if(nums[0] <= target){
            prev[nums[0]] = true;
        }

        for(int ind = 1; ind < n; ind++){
            boolean curr[] = new boolean[target + 1];
            curr[0] = true;
            for(int j = 1; j <= target; j++){
                boolean notTake = prev[j], Take = false;
                if(j >= nums[ind]){
                    Take = prev[j - nums[ind]];
                }
                curr[j] = notTake || Take;
            }
            prev = curr;
        }
        
        return prev[target];
    }
}