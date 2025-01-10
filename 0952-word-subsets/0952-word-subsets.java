class Solution {
    private boolean fun(int arr1[], int arr2[]){
        for(int i = 0; i < 26; i++){
            if(arr1[i] < arr2[i]){
                return false;
            }
        }
        return true;
    }

    public List<String> wordSubsets(String[] words1, String[] words2) {
        int n = words1.length, freq1[][] = new int[n][26];
        for(int i = 0; i < n; i++){
            for(char ch : words1[i].toCharArray()){
                freq1[i][ch - 'a']++;
            }
        }

        int m = words2.length, freq2[] = new int[26];
        for(int i = 0; i < m; i++){
            int temp[] = new int[26];
            for(char ch : words2[i].toCharArray()){
                temp[ch - 'a']++;
                freq2[ch - 'a'] = Math.max(freq2[ch - 'a'], temp[ch - 'a']);
            }
        }
        
        List<String> ans = new ArrayList<>();
        for(int i = 0; i < n; i++){
            if(fun(freq1[i], freq2)){
                ans.add(words1[i]);
            }
        }

        return ans;
    }
}