class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a(1001, 0), b(1001, 0), ans;
        for(int i : nums1)  a[i]++;
        for(int i : nums2)  b[i]++;
        for(int i = 0; i <= 1000; i++){
            if(a[i] && b[i]){
                int leastCnt = min(a[i], b[i]);
                while(leastCnt--){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};