class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int j = 0, ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < fruits.size(); i++){
            mp[fruits[i]]++;
            while(mp.size() > 2){
                mp[fruits[j]]--;
                if(mp[fruits[j]] == 0){
                    mp.erase(fruits[j]);
                }
                j++;
            }
            int sum = 0;    for(auto it : mp)   sum += it.second;
            ans = max(ans, sum);
        }

        return ans;
    }
};