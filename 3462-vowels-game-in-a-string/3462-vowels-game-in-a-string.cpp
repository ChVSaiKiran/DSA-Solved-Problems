class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(char i : s){
            if(i == 'a' || i == 'e' || i == 'o' || i == 'i' || i == 'u'){
                cnt++;
            }
        }

        return cnt > 0;
    }
};