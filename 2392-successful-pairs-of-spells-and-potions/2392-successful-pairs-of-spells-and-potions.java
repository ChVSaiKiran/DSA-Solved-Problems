class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length, m = potions.length, ans[] = new int[n];
        Arrays.sort(potions);
        for(int i = 0; i < n; i++){
            long spell = spells[i];
            int low = 0, high = potions.length - 1, idx = m;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(potions[mid] * spell >= success){
                    idx = mid;
                    high = mid - 1;
                } else{
                    low = mid + 1;
                }
            }
            ans[i] = m - idx;
        }
        return ans;
    }
}