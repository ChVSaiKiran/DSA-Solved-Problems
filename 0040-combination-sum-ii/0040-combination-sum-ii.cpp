class Solution {
private:
    void f(vector<int>& candidates, vector<int>& temp, int target, int ind, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = ind; i < candidates.size(); ++i) {
            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            
            if (candidates[i] > target) break;

            temp.push_back(candidates[i]);
            f(candidates, temp, target - candidates[i], i + 1, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        f(candidates, temp, target, 0, ans);
        return ans;
    }
};
