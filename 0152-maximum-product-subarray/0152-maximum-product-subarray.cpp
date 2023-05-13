class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxi = INT_MIN;
	    long long prefix = 0, sufix = 0, n = nums.size();
	    for(long long i = 0; i < n; i++){
	        if(prefix == 0) prefix++;
	        if(sufix == 0) sufix++;
	        prefix *= nums[i];
	        sufix *= nums[n - 1 - i];
	        maxi = max(maxi,max(prefix,sufix));
	    }
	    return maxi;
    }
};