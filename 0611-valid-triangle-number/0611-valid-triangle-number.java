class Solution {
    public int triangleNumber(int[] nums) {
        int n = nums.length, cnt = 0;
        Arrays.sort(nums);
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                int low = j + 1, high = n - 1, validInd = -1;
                while(low <= high){
                    int mid = low + (high - low) / 2;
                    if(nums[mid] < nums[i] + nums[j]){
                        validInd = mid;
                        low = mid + 1;
                    } else{
                        high = mid - 1;
                    }
                }
                if(validInd != -1){
                    cnt += (validInd - j);
                }
            }
        }
        return cnt;
    }
}