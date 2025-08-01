class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(256, 0);
        for(char c : s) freq[c]++;
        for(char c : t) freq[c]--;
        for(int i : freq){
            if(i != 0)  return false;
        }
        return true;
    }
};