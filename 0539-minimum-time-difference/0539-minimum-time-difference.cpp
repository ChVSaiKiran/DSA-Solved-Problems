#define F first
#define S second
class Solution {
private:
    int f(pair<int,int> &a, pair<int,int> &b){
        int x = a.F * 60 + a.S;
        int y = b.F * 60 + b.S;
        int diff = abs(x - y);
        return min(diff, 1440 - diff);
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<pair<int,int>> arr;
        arr.reserve(n);

        for(auto &s : timePoints){
            int h = stoi(s.substr(0, 2));
            int m = stoi(s.substr(3, 2));
            arr.push_back({h, m});
        }

        sort(arr.begin(), arr.end());

        int ans = INT_MAX;
        for(int i = 0; i < n - 1; i++){
            ans = min(ans, f(arr[i], arr[i + 1]));
        }

        ans = min(ans, f(arr[0], arr[n - 1]));

        return ans;
    }
};