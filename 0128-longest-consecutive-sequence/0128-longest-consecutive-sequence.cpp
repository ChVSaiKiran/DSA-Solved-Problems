class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i: nums)
            s.insert(i);
        int ans = 0;
        for(int i: s){
            if(s.find(i - 1) == s.end()){
                int start = 1;
                int cnt = 1;
                while(s.find( i + start) != s.end()){
                    cnt++;
                    start++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};