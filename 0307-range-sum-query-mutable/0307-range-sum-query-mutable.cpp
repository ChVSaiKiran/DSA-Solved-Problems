class NumArray {
private:
    int n, m;
    vector<int> seg;

    int getSegSize(int n){
        int cnt = (n & (n - 1)) != 0;
        while(n > 0){
            cnt++;  n = n >> 1;
        }
        return (1 << cnt) - 1;
    }

    int build(vector<int> &nums, int l, int r, int pos){
        if(l == r){
            return seg[pos] = nums[l];
        }
        int m = (l + r) / 2;
        int lt = build(nums, l, m, 2 * pos + 1);
        int rt = build(nums, m + 1, r, 2 * pos + 2);
        return seg[pos] = lt + rt;
    }

    int updateVal(int l, int r, int pos, int idx, int val){
        int d = 0;
        if(l == r && l == idx){
            d = val - seg[pos];
        }else if(l <= idx && idx <= r){
            int m = (l + r) / 2;
            d = (updateVal(l, m, 2 * pos + 1, idx, val) + updateVal(m + 1, r, 2 * pos + 2, idx, val));
        }
        seg[pos] += d;
        return d;
    }

    int getSum(int l, int r, int pos, int inpL, int inpR){
        if(inpL <= l && r <= inpR){
            return seg[pos];
        }

        if(inpR < l || r < inpL){
            return 0;
        }

        int m = (l + r) / 2;
        return getSum(l, m, 2 * pos + 1, inpL, inpR) + getSum(m + 1, r, 2 * pos + 2, inpL, inpR);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        m = getSegSize(n);
        seg.resize(m, 0);
        build(nums, 0, n - 1, 0);
    }
    
    void update(int index, int val) {
        updateVal(0, n - 1, 0, index, val);
    }
    
    int sumRange(int left, int right) {
        return getSum(0, n - 1, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */