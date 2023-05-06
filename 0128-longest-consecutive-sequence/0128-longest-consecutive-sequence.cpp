class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i: nums)
            s.insert(i);
        int ans = 0;
        for(int i: s){
            if(s.find(i) == s.end())
                continue;
            int prev = i - 1, next = i + 1;
            while(s.find(prev) != s.end())
                s.erase(prev--);
            while(s.find(next) != s.end())
                s.erase(next++);
            ans = max(ans,next - prev - 1);
        }
        return ans;
    }
};