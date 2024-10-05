class Solution {
    bool check(vector<int> &a, vector<int> &b){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> a(26, 0), b(26, 0);
        for(char i : s1){
            a[i - 'a']++;
        }

        for(int i = 0; i < s2.size(); i++){
            b[s2[i] - 'a']++;
            if(i >= s1.size() - 1){
                if(check(a, b)){
                    return true;
                }
                b[s2[i - s1.size() + 1] - 'a']--;
            }
        }

        return false;
    }
};