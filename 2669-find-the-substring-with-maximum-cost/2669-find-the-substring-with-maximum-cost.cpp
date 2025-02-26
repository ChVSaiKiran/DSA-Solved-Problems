class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> mp(26, -2000);
        for(int i = 0; i < chars.size(); i++){
            mp[chars[i] - 'a'] = vals[i];
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(mp[ch - 'a'] == -2000){
                mp[ch - 'a'] = ch - 'a' + 1;
            }
        }

        int ans = 0, sum = 0;
        for(char ch : s){
            sum += mp[ch - 'a'];
            if(sum < 0) sum = 0;
            ans = max(ans, sum);
        }

        return ans;
    }
};