class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int> maxQ, minQ;
        long long l = 0, n = nums.size(), ans = 0;
        for(long long r = 0; r < n; r++){
            while(!maxQ.empty() && nums[maxQ.back()] < nums[r]){
                maxQ.pop_back();
            }

            while(!minQ.empty() && nums[minQ.back()] > nums[r]){
                minQ.pop_back();
            }

            maxQ.push_back(r);  minQ.push_back(r);

            while(!minQ.empty() && !maxQ.empty() && ((long long)(nums[maxQ.front()] - nums[minQ.front()]) * (r - l + 1) > k)){
                if(maxQ.front() == l){
                    maxQ.pop_front();
                }

                if(minQ.front() == l){
                    minQ.pop_front();
                }

                l++;
            } 

            ans += (r - l + 1);
        }

        return ans;
    }
};