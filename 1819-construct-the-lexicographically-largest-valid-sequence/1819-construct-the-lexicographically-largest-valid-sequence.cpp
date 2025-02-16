class Solution {
private:
    bool fun(vector<int> &ans, vector<bool> &vis, int n, int idx){
        if(idx == ans.size()){
            return true;
        }

        if(ans[idx] != -1){
            return fun(ans, vis, n, idx + 1);
        }

        for(int i = n; i >= 1; i--){
            if(!vis[i] && ans[idx] == -1){
                if(i != 1 && idx + i >= ans.size()){
                    return false;
                }
                
                if(i == 1 || ans[i + idx] == -1){
                    ans[idx] = i;   vis[i] = true;
        
                    if(i != 1){
                        ans[idx + i] = i;
                    }
        
                    if(fun(ans, vis, n, idx + 1)){
                        return true;
                    }
        
                    if(i != 1){
                        ans[idx + i] = -1;
                    }
        
                    ans[idx] = -1;  vis[i] = false;
                }
            }
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {        
        vector<bool> vis(n + 1, false);
        vector<int> ans(2*n - 1, -1);
        fun(ans, vis, n, 0);
        return ans;
    }
};