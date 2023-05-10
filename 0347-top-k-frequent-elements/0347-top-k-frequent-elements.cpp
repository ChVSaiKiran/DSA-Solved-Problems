class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            unordered_map<int, int> mp;
            for (int i: nums)
                mp[i]++;
            vector<vector<int>> freq;
            freq.reserve(mp.size());
            for (auto it: mp)
                freq.push_back({ it.second,it.first });
            sort(freq.begin(), freq.end());
            vector<int> ans;
            int i = freq.size() - 1;
            while(k--)
                ans.emplace_back(freq[i--][1]);
            return ans;
        }
};