class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        boolean x = false, y = false;
        for(int i : arr){
            if(x && y && i % 2 == 1){
                return true;
            }
            x = y;
            y = i % 2 == 1;
        }
        return false;
    }
}