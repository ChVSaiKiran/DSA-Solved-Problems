class Solution {
private:
    string fun(string s){
        int cnt = 1;
        string temp;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i - 1]){
                cnt++;
            } else{
                temp += (to_string(cnt) + s[i - 1]);
                cnt = 1;
            }
        }
        temp += (to_string(cnt) + s.back());
        return temp;
    }
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++){
            ans = fun(ans);
        }
        return ans;
    }
};