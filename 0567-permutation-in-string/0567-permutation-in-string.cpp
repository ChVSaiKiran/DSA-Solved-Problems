class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        unordered_map<char,int> mp1, mp2;
        for(char i:s1)
            mp1[i]++;
        for(int i = 0; i < s1.length(); i++)
            mp2[s2[i]]++;
        int n = s1.length(), i = n;
        for(int i = n; i < s2.length(); i++){
            if(mp1 == mp2)
                return true;
            mp2[s2[i - n]]--;
            if(mp2[s2[i - n]] == 0)
                mp2.erase(s2[i - n]);
            mp2[s2[i]]++;
        }
        return mp1 == mp2;
    }
};