class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long long> temp;;
        long long sum = 0;
        for(int i : chalk){
            sum += i;
            temp.push_back(sum);
        }

        k %= sum;
        int l = 0, h = chalk.size() - 1, ans = 0;
        while(l <= h){
            int m = l + (h - l) / 2;
            if(temp[m] == k){
                return m + 1;
            } else if(temp[m] < k){
                l = m + 1;
            } else{
                ans = m;
                h = m - 1;
            }
        }

        return ans;
    }
};