class Solution {
public:
    int numSquares(int num) {
        vector<int> arr;
        for(int i = 1; i * i <= num; i++){
            arr.emplace_back(i * i);
        }

        int n = arr.size();
        vector<int> prev(num + 1, 0);

        for(int val = 0; val <= num; val++){
            prev[val] = val;
        }

        for(int i = 1; i < n; i++){
            vector<int> curr(num + 1, 0);
            for(int val = 0; val <= num; val++){
                int x = prev[val];
                int y = (arr[i] > val) ? (int)1e9 : 1 + curr[val - arr[i]];
                curr[val] = min(x, y);
            }
            prev = curr;
        }

        return prev[num];
    }
};