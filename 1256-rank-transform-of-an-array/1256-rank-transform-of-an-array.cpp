class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        for(int i : arr){
            mp[i]++;
        }
        int cnt = 1;
        for(auto &it : mp){
            it.second = cnt++;
        }

        vector<int> ans;
        ans.reserve(arr.size());

        for(int i : arr){
            ans.push_back(mp[i]);
        }

        return ans;
    }
};