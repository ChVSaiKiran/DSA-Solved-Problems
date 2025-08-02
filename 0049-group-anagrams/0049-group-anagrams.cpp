class Solution {
private:
    size_t getHash(string &str){
        vector<int> freq(26, 0);
        for(char c : str)  freq[c - 'a']++;

        int multiplier = 31;
        size_t hashValue = 0;
        for(int i : freq){
            hashValue = hashValue * multiplier + hash<int>{}(i);
        }
        return hashValue;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<size_t, vector<string>> mp;
        for(string str : strs){
            mp[getHash(str)].push_back(str);
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};