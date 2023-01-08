class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.size();
        unordered_map <char,char> dict;
        unordered_map <char,int> flag;
        for(int i = 0; i < n; i++)
        {
            auto it = dict.find(s[i]);
            if(it == dict.end())
            {
                if(flag.find(t[i]) == flag.end())
                {
                    dict[s[i]] = t[i];
                    flag[t[i]] = 1;
                }
                else
                    return false;
            }
            else if(it->second != t[i])
                return false;
        }
        return true;
    }
};