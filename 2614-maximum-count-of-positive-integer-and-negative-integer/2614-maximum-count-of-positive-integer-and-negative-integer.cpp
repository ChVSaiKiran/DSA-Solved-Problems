class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        for(int i : nums){
            if(i > 0)   cnt1++;
            else if(i < 0)  cnt2++;
        }
        return max(cnt1, cnt2);
    }
};