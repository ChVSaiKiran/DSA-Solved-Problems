class Solution {
private:

public:
    int numRabbits(vector<int>& answers) {
        vector<int> mp(1001, 0);
        for(int i : answers){
            mp[i]++;
        }

        int ans = mp[0];
        for(int i = 1; i <= 1000; i++){
            int val = (mp[i] / (i + 1)) + ((mp[i] % (i + 1)) != 0);
            ans += (val * (i + 1));
        }

        return ans;
    }
};