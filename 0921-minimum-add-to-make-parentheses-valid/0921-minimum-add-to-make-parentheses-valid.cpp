class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, cnt = 0;
        for(char i : s){
            if(i == '('){
                cnt++;
            } else if(cnt > 0){
                cnt--;
            } else{
                ans++;
            }
        }

        return ans + cnt;
    }
};