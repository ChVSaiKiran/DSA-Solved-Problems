class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = words.length, temp[] = new int[n], cnt = 0;
        for(int i = 0; i < n; i++){
            char a = words[i].charAt(0), b = words[i].charAt(words[i].length() - 1);
            if((a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') && (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u')){
                cnt++;
            }
            temp[i] = cnt;
        }

        int m = queries.length, ans[] = new int[m];

        for(int i = 0; i < m; i++){
            int l = queries[i][0], r = queries[i][1];
            ans[i] = temp[r] - (l > 0 ? temp[l - 1] : 0);
        }

        return ans;
    }
}