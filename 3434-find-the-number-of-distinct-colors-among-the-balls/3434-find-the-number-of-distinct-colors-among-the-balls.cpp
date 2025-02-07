class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size(), cnt = 0;
        vector<int> ans(n);
        unordered_map<int,int> labels, colors;
        
        for(int i = 0; i < n; i++){
            int x = queries[i][0];
            int y = queries[i][1];

            if(labels.find(x) != labels.end()){
                int prevColor = labels[x];
                colors[prevColor]--;
                if(colors[prevColor] == 0){
                    colors.erase(prevColor);
                }    
            }

            labels[x] = y;
            colors[y]++;
            
            ans[i] = colors.size();
        }

        return ans;
    }
};