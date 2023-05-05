class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int ans = 0, sum = 0;
        for(int i:nums){
            sum += i;
            if(sum == k)
                ans++;
            if(hash.find(sum - k) != hash.end())
                ans += hash[sum - k];
            hash[sum]++;
        }
        return ans;
    }
};