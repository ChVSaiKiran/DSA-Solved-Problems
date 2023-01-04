class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> arr;
        for(auto i:tasks)
            arr[i]++;
        int ans  = 0;
        for(auto it:arr){
            int val = it.second;
            if(val == 1)
                return -1;
            if(val%3 == 0)
                ans += val/3;
            else
                ans += val/3 + 1;
        }
        return ans;
    }
};