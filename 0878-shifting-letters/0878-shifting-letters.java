class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        long sum = 0;
        StringBuffer sb = new StringBuffer();
        for(int i = shifts.length - 1; i >= 0; i--){
            sum += shifts[i];
            long n = s.charAt(i) - 'a';
            n = (n + sum) % 26;
            sb.append((char)('a' + n));
        }
        return sb.reverse().toString();
    }
}