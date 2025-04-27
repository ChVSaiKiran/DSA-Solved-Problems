class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), m = n - k;
        long sum = 0, temp = 0, minSum = LLONG_MAX;
        
        for(int i = 0; i < m; i++){
            sum += cardPoints[i];
            temp += cardPoints[i];
        }
        minSum = min(temp, minSum);

        for(int i = m; i < n; i++){
            sum += cardPoints[i];
            temp += cardPoints[i] - cardPoints[i - m];
            minSum = min(temp, minSum);
        }

        return sum - minSum;
    }
};