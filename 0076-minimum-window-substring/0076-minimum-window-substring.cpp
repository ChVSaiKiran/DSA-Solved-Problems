class Solution {
    int f(char &ch){
        if(ch <= 'Z'){
            return ch - 'A';
        }
        return ch - 'a' + 26;
    }

public:
    string minWindow(string s, string t) {
        int n = s.size(), k = 0;

        vector<int> a(52, 0), b(52, 0);
        for(char i : t)  b[f(i)]++;
        for(int i : b)  k += (i > 0);

        int l = 0, ansLen = n + 1, match = 0;
        pair<int,int> ans = {-1, -1};

        for(int r = 0; r < n; r++){
            int idx1 = f(s[r]);
            if(++a[idx1] == b[idx1] && b[idx1] != 0){
                match++;
            }

            while(match == k){
                int len = r - l + 1;
                if(ansLen > len){
                    ans = {l, len};
                    ansLen = len;
                }

                int idx2 = f(s[l++]);
                if(a[idx2]-- == b[idx2] && b[idx2] != 0){
                    match--;
                }
            }
        }
        
        return ans.first == -1 ? "" : s.substr(ans.first, ans.second);
    }
};