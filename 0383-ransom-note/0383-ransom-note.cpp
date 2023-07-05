class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length())
            return false;
        vector<int> freq(26,0);
        for(char i:magazine)
            freq[i - 'a']++;
        for(char i:ransomNote)
            freq[i - 'a']--;
        for(int i:freq)
            if(i < 0)
                return false;
        return true;
    }
};