class Solution {
    public boolean canConstruct(String s, int k) {
        int n = s.length();
        if(n < k){
            return false;
        }

        int freq[] = new int[26];
        for(char ch : s.toCharArray()){
            freq[ch - 'a']++;
        }

        int odd = 0, even = 0;
        for(int i : freq){
            if(i % 2 == 1){
                odd++;
            } else if(i != 0){
                even++;
            }
        }
        
        return odd <= k;
    }
}