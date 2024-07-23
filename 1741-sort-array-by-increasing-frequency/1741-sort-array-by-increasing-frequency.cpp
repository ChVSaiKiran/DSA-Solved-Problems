class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int &i : nums){
            mp[i]++;
        }
        vector<pair<int,int>> temp(mp.begin(), mp.end());
        sort(temp.begin(), temp.end(), [](pair<int,int> a, pair<int,int> b){
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        });
        vector<int> ans;
        for(auto it : temp){
            for(int i = 0; i < it.second; i++){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};