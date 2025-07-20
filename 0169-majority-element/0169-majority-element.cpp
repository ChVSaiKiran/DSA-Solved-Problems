class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, val = -1;
        for(int i : nums){
            if(i == val){
                cnt++;
            } else if(cnt == 0){
                cnt = 1;    val = i;
            } else{
                cnt--;
            }
        }
        return val;
    }
};