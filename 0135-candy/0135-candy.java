class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length, temp[] = new int[n];
        for(int i = 0; i < n; i++){
            temp[i] = 1;
        }
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                temp[i] = temp[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1] && temp[i] <= temp[i + 1]){
                temp[i] = temp[i + 1] + 1;
            }
        }
        int ans = 0;
        for(int i : temp)
            ans += i;
        return ans;
    }
}