class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501);
        for(int i : nums)   freq[i]++;
        for(int i : freq){
            if(i & 1)   return false;
        }
        return true;
    }
};