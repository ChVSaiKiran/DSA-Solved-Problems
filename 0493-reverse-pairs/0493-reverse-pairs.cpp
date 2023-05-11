class Solution {
    int merge(vector<int> &arr, int lo, int mid, int hi){
        int j = mid + 1;
        int cnt  = 0;
        for(int i = lo; i <= mid; i++){
            while(j <= hi && arr[i] > 2 * (long long)arr[j])
                j++;
            cnt += (j-(mid + 1));
        }
        vector<int> temp;
        int i = lo;
        j = mid + 1;
        while(i <= mid && j <= hi){
            if(arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        while(i <= mid)
            temp.push_back(arr[i++]);
        while(j <= hi)
            temp.push_back(arr[j++]);
        for(int i = lo; i <= hi; i++)
            arr[i] = temp[i - lo];
        return cnt;
    }
    int mergesort(vector<int> &arr, int lo, int hi){
        if(lo >= hi)
            return 0;
        int mid = (hi + lo) / 2, cnt = 0;
        cnt += mergesort(arr,lo,mid);
        cnt += mergesort(arr,mid+1,hi);
        cnt += merge(arr,lo,mid,hi);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size() - 1);
    }
};