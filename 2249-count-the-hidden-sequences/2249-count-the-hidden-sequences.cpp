class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long psum = differences[0];
        long long mini = differences[0];
        long long maxi = differences[0];

        for(int i = 1; i < n; i++){
            psum += differences[i];
            mini = min(psum, mini);
            maxi = max(psum, maxi);
        }

        int ans = min((long long) upper, (upper - maxi)) - max((long long)lower, (lower - mini)) + 1;
        return max(ans, 0);
    }
};