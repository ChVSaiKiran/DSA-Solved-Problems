class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &strs)
        {
            int n = strs.size();
            vector<string> dumm(strs), temp;
            vector<int> len(n);
            for (int i = 0; i < n; i++)
            {
                sort(dumm[i].begin(), dumm[i].end());
                len[i] = dumm[i].length();
            }
            vector<vector < string>> ans;
            for (int i = 0; i < n; i++)
            {
                if (len[i] == -1) continue;
                vector<string> temp(1,strs[i]);
                for (int j = i + 1; j < n; j++)
                    if (len[i] != -1 && len[i] == len[j] && dumm[i] == dumm[j])
                    {
                        temp.push_back(strs[j]);
                        len[j] = -1;
                    }
                ans.push_back(temp);
            }
            return ans;
        }
};