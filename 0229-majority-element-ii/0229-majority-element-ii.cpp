class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = INT_MIN, ele2 = INT_MIN, cnt1 = 0, cnt2 = 0;
        for(int i : nums){
            if(i == ele1){
                cnt1++;
            } else if(i == ele2){
                cnt2++;
            } else if(cnt1 == 0){
                ele1 = i; cnt1++;
            } else if(cnt2 == 0){
                ele2 = i; cnt2++;   
            } else{
                cnt1--; cnt2--;
            }
        }

        cnt1 = 0;   cnt2 = 0;
        for(int i : nums){   
            cnt1 += (i == ele1);
            cnt2 += (i == ele2);
        }

        int n = nums.size();
        vector<int> ans;    
        if(cnt1 > n / 3){
            ans.push_back(ele1);
        }

        if(cnt2 > n / 3){
            ans.push_back(ele2);
        }

        return ans;
    }
};