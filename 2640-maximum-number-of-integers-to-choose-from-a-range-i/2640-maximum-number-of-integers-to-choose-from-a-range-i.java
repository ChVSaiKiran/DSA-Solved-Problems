class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        int size = (int)Math.min(1e4 + 1, n + 1), temp[] = new int[size];
        Arrays.fill(temp, 1);

        for(int i : banned){
            if(i <= n){
                temp[i] = 0;
            }
        }

        int cnt = 0, sum = 0;
        for(int i = 1; i < size; i++){
            if(temp[i] == 0){
                continue;
            } else if(sum + i > maxSum){
                break;
            } else{
                sum += i;
                cnt++;
            }
        }

        return cnt;
    }
}