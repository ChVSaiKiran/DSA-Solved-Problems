class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, el1 = -1, el2 = -1;
        int n = nums.size();
        for(int i: nums){
            if(cnt1 == 0 && el2 != i){
                cnt1 = 1;
                el1 = i;
            }
            else if(cnt2 == 0 && el1 != i){
                el2 = i;
                cnt2 = 1;
            }
            else if(el1 == i)
                cnt1++;
            else if(el2 == i)
                cnt2++;
            else
                cnt1--,cnt2--;
        }
        cnt1 = cnt2 = 0;
        for(int i:nums){
            cnt1 += el1 == i ? 1:0;
            cnt2 += el2 == i ? 1:0;
        }
        vector<int> ans;
        if(cnt1 > n / 3)
            ans.push_back(el1);
        if(cnt2 > n / 3 && el1 != el2)
            ans.push_back(el2);
        return ans;
    }
};