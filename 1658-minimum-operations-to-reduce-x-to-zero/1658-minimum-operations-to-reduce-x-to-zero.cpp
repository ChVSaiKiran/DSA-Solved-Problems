class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        unordered_map<int,int> dict;
        int n = arr.size(), sum = 0;
        for(int i = n - 1; i >= 0; i--){
            sum += arr[i];
            dict[sum] = n - i;
        }
        sum = 0;
        int ans = n + 1;
        
        if(dict.find(x) != dict.end())
            ans = dict[x];
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(sum == x)
                ans = min(ans, i + 1);
            
            if(dict.find(x - sum) != dict.end())
                ans = min(ans, i + 1 + dict[x - sum]);
        }
        if(ans == n + 1)
            return -1;
        return ans;
    }
};