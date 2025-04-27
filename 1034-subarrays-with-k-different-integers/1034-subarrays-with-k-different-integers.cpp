class Solution {
private:
    // Approach 1
    int fun1(vector<int> &nums, int k){
        long cnt = 0, l = 0, n = nums.size();
        unordered_map<int, int> mp;
        for(int r = 0; r < n; r++){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }

    // Approach 2
    int fun2(vector<int> &nums, int k){
        int cnt = 0, n = nums.size();
        int l1 = 0, unq1 = 0, l2 = 0, unq2 = 0;

        vector<int> d1(20001, 0), d2(20001, 0);

        for(int r = 0; r < n; r++){
            d1[nums[r]]++;  unq1 += (d1[nums[r]] == 1);
            while(unq1 > k){
                d1[nums[l1]]--;
                unq1 -= (d1[nums[l1++]] == 0);
            }

            d2[nums[r]]++;  unq2 += (d2[nums[r]] == 1);
            while(unq2 > k - 1){
                d2[nums[l2]]--;
                unq2 -= (d2[nums[l2++]] == 0);
            }

            cnt += ((r - l1 + 1) - (r - l2 + 1));
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // return fun1(nums, k) - fun1(nums, k - 1);
        return fun2(nums, k);
    }
};