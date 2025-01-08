class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        int cnt = 0, n = words.length;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                cnt += (words[i].startsWith(words[j]) && words[i].endsWith(words[j])) ? 1 : 0;
            }
        }
        return cnt;
    }
}