class Solution {
    public int secondHighest(String s) {
        int max1 = -1, max2 = -1;
        for(char i:s.toCharArray()){
            if(i < '0' || i > '9')
                continue;
            int x = i - 48;
            if(x == max1)
                continue;
            if(x > max1)
            {
                max2 = max1;
                max1 = x;
            }
            else if(x > max2)
                max2 = x;
        }
        return max2;
    }
}