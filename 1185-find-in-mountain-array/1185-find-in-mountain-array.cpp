/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int getPeakIndex(MountainArray &mountainArr){
        int n = mountainArr.length();
        if(n < 3)   return -1;
        int l = 1, r = n - 2;
        while(l <= r){
            int m = l + (r - l) / 2;
            int x = mountainArr.get(m - 1);
            int y = mountainArr.get(m);
            int z = mountainArr.get(m + 1);
            if(x < y && y > z){
                return m;
            } else if(x < y){
                l = m + 1;
            } else{
                r = m - 1;
            }
        }
        return -1;
    }

    int findUsingBs(int l, int r, MountainArray &mountainArr, int target, bool flag){
        while(l <= r){
            int m = l + (r - l) / 2;
            int val = mountainArr.get(m);
            if(val == target){
                return m;
            } else if(val < target){
                if(flag)
                    l = m + 1;
                else
                    r = m - 1;
            } else{
                if(flag)
                    r = m - 1;
                else
                    l = m + 1;
            }
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIdx = getPeakIndex(mountainArr);
        if(peakIdx == -1){
            return -1;
        }

        int ans = findUsingBs(0, peakIdx, mountainArr, target, true);
        if(ans == -1){
            ans = findUsingBs(peakIdx + 1, mountainArr.length() - 1, mountainArr, target, false);
        }

        return ans;
    }
};