class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < arr.size(); i++){
            int dis = arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1];
            pq.push({-dis,i});
        }
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(arr[pq.top().second]);
                pq.pop();
        }
        return ans;
    }
};