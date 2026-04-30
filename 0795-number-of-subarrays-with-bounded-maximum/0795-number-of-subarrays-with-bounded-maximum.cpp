class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        stack<int> s;
        int n = nums.size();


        vector<int> nge(n, 0);
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && nums[s.top()] <= nums[i]){
                s.pop();
            }
            if(s.empty()){
                nge[i] = n;
            } else{
                nge[i] = s.top();
            }
            s.push(i);
        }

        stack<int>().swap(s);
        vector<int> pge(n, 0);
        for(int i = 0; i < n; i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                s.pop();
            }
            if(s.empty()){
                pge[i] = -1;
            } else{
                pge[i] = s.top();
            }
            s.push(i);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(left <= nums[i] && right >= nums[i]){
                int l = pge[i], r = nge[i];
                cnt += (i - l) * (r - i);
            } 
        }

        return cnt;
    }
};