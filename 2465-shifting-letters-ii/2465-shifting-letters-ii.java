class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length(), temp[] = new int[n + 1];
        
        for(int[] r : shifts){
            int start = r[0], end = r[1] + 1, d = r[2];
            if(d == 0){
                temp[start] -= 1;
                temp[end] += 1;
            } else{
                temp[start] += 1;
                temp[end] -= 1;
            }
        }

        long sum = 0;
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < n; i++){
            sum += temp[i];
            long ch = s.charAt(i) - 'a';
            if(sum >= 0){
                ch = (ch + sum) % 26;
            } else{
                ch += (sum % 26);
                if(ch < 0) ch += 26;
            }
            sb.append((char)('a' + ch));
        }

        return sb.toString();
    }
}