class Solution {
    public int buttonWithLongestTime(int[][] events) {
        int ind = events[0][0], time = events[0][1];
        for(int i = 1; i < events.length; i++){
            int temp = events[i][1] - events[i - 1][1];
            if(temp > time){
                time = temp;
                ind = events[i][0];
            } else if(time == temp){
                ind = Math.min(ind, events[i][0]);
            }
        }
        return ind;
    }
}