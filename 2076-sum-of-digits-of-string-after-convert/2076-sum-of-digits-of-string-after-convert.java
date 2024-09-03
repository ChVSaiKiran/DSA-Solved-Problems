class Solution {
    public int getLucky(String s, int k) {
        int sum = 0;
        for(char i : s.toCharArray()){
            int digit = i - 'a' + 1;
            while(digit > 0){
                sum += digit % 10;
                digit /= 10;
            }
        }
        
        for(int i = 1; i < k; i++){
            int temp = 0;
            while(sum > 0){
                temp += sum % 10;
                sum /= 10;
            }
            sum = temp;
        }

        return sum;
    }
}