class Solution {
private:
    long long fun(vector<int>& ranks, int cars, long long time){
        long long cnt = 0;
        for(int i : ranks){
            long long temp = time / i;
            cnt += sqrt(temp);
        }
        return cnt >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, ans = 0;
        long long high = *max_element(ranks.begin(), ranks.end());
        high *= cars;
        high *= cars;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(fun(ranks, cars, mid)){
                ans = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return ans;
    }
};