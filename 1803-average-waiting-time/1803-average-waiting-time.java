class Solution {
    public double averageWaitingTime(int[][] customers) {
        int n = customers.length, finishTime = 0;
        double ans = 0;
        for(int i = 0; i < n; i++){
            if(customers[i][0] > finishTime)
                finishTime = customers[i][0];
            finishTime += customers[i][1];
            ans += (finishTime - customers[i][0]);
        }
        return (ans / n);
    }
}