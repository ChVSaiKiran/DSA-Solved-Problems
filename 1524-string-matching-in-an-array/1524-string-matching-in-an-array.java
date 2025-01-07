class Solution {
    public List<String> stringMatching(String[] words) {
        List<String> ans = new ArrayList<>();
        boolean vis[] = new boolean[words.length];

        Arrays.sort(words, (word1, word2) -> Integer.compare(word1.length(), word2.length()));
        for(int i = 1; i < words.length; i++){
            for(int j = 0; j < i; j++){
                if(!vis[j] && words[i].indexOf(words[j]) != -1){
                    vis[j] = true;
                    ans.add(words[j]);
                }
            }
        }
        return ans;
    }
}