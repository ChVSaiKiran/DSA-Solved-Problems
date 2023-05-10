class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans = {arr[0]};
        for(int i = 1; i < n; i++){
            vector<int> temp = ans.back();
            if(temp[1] >= arr[i][0]){
                ans.pop_back();
                if(temp[1] < arr[i][1]) ans.push_back({temp[0],arr[i][1]});
                else    ans.push_back(temp);
            }
            else
                ans.push_back(arr[i]);
        }
        return ans;
    }
};