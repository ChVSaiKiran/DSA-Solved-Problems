class Solution {
    int f(char &ch){
        if(ch <= 'Z'){
            return ch - 'A';
        }
        return ch - 'a' + 26;
    }

    bool check(vector<int> &a, vector<int> &b){
        for(int i = 0; i < 52; i++){
            if(a[i] < b[i]){
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        int n1 = s.size(), n2 = t.size();

        vector<int> a(52, 0), b(52, 0);
        for(char i : t){
           b[f(i)]++;
        }

        int j = 0, ansLen = n1 + 1;
        pair<int,int> ans = {-1, -1};

        for(int i = 0; i < n1; i++){
            a[f(s[i])]++;
            if(i - j + 1 >= n2){
                while(check(a, b)){
                    int len = i - j + 1;
                    if(len < ansLen){
                        ansLen = len;
                        ans = {j, ansLen};
                    }
                    a[f(s[j])]--;
                    j++;
                }
            }
        }

        if(ans.first == -1){
            return "";
        }

        return s.substr(ans.first, ans.second);
    }
};