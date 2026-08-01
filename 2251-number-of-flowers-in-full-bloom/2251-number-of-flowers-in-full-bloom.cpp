class Solution {
private:
    int solve(int time, vector<pair<int, int>> &arr){
        int l = 0, r = arr.size() - 1, res = 0;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(arr[m].first == time){
                return arr[m].second;
            } else if(arr[m].first < time){
                res = arr[m].second; l = m + 1;
            } else{
                r = m - 1;
            }
        }
        return res;
    }

public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> mp;
        for(auto it : flowers){
            mp[it[0]]++; mp[it[1] + 1]--;
        }

        int sum = 0;
        vector<pair<int, int>> arr; arr.reserve(mp.size());
        for(auto it : mp){
            sum += it.second;
            arr.push_back(make_pair(it.first, sum)); //(time, active)
        }

        vector<int> res; res.reserve(people.size());
        for(int &i : people){
            res.push_back(solve(i, arr));
        }

        return res;
    }
};