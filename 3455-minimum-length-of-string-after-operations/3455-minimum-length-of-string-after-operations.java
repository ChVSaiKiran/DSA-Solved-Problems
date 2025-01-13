class Solution {
    public int minimumLength(String s) {
        int n = s.length(), freq[] = new int[26];
        for(char ch : s.toCharArray()){
            freq[ch - 'a']++;
            if(freq[ch - 'a'] > 2){
                n -= 2;
                freq[ch - 'a'] -= 2;
            }
        }
        return n;
    }
}