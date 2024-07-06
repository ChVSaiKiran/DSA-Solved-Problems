class Solution {
    public int passThePillow(int n, int time) {
        int i = 1;
        while(true){
            if(i == 1){
                if(i + time <= n){
                    return i + time;
                } else{
                    i = n;
                    time = time - (n - 1);
                }
            } else{
                if(i - time >= 1){
                    return i - time;
                } else{
                    i = 1;
                    time = time - (n - 1);
                }
            }
        }
    }
}