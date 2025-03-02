class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        ans.reserve(max(n, m));

        for(int id = 1; id <= 1000 && (i < n || j < m); id++){
            int val = 0;
            if(i < n && nums1[i][0] == id){
                val += nums1[i++][1];
            }

            if(j < m && nums2[j][0] == id){
                val += nums2[j++][1];
            }

            if(val != 0){
                ans.push_back({id, val});
            }
        }

        return ans;
    }
};