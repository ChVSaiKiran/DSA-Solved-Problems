class Solution {
    private int fun(int n, int[] temp){
        if(temp[n] != 0){
            return temp[n];
        }

        int ans = n;
        for(int i = 1; i < n; i++){
            ans = Math.max(ans, i * fun(n - i, temp));
        }

        return temp[n] = ans;
    }

    public int integerBreak(int n) {
        if(n == 3){
            return 2;
        }
        
        int temp[] = new int[n + 1];
        temp[1] = 1;
        temp[2] = 1;
        return fun(n, temp);
    }
}