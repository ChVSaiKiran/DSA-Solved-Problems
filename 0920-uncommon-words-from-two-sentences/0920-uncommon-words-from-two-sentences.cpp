class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        string temp;
        stringstream ss1(s1), ss2(s2);
        while(ss1 >> temp){
            mp[temp]++;
        }

        while(ss2 >> temp){
            mp[temp]++;
        }

        vector<string> ans;
        ans.reserve(mp.size());
        
        for(auto it : mp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};