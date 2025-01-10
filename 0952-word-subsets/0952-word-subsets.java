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
        int n = words1.length, m = words2.length, req[] = new int[26];
        for(int i = 0; i < m; i++){
            int temp[] = new int[26];
            for(char ch : words2[i].toCharArray()){
                temp[ch - 'a']++;
                req[ch - 'a'] = Math.max(req[ch - 'a'], temp[ch - 'a']);
            }
        }
        
        List<String> ans = new ArrayList<>();
        for(int i = 0; i < n; i++){
            int curr[] = new int[26];
            for(char ch : words1[i].toCharArray()){
                curr[ch - 'a']++;
            }
            if(fun(curr, req)){
                ans.add(words1[i]);
            }

        }
        
        return ans;
    }
}