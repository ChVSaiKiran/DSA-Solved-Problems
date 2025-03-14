class Solution {
private:
    bool fun(vector<int>& candies, int val, long long k){
        for(int i : candies){
            k -= (i / val);
            if(k <= 0)  return true;
        }
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = *max_element(candies.begin(), candies.end()), ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(fun(candies, mid, k)){
                low = mid + 1;
                ans = mid;
            } else{
                high = mid - 1;
            }
        }
        return ans;
    }
};