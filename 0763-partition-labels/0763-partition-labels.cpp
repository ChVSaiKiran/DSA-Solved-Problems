class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i < s.length(); i++)
            mp[s[i]] = i;
        vector<int> ans;
        int i = 0;
        while(i < s.length()){
            char key = s[i];
            for(int j = i; j < mp[key]; j++)
                if(mp[s[j]] > mp[key])
                    key = s[j];
            ans.push_back(abs(i - mp[key]) + 1);
            i = mp[key] + 1;
        }
        return ans;
    }
};