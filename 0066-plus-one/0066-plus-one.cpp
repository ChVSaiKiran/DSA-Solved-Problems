class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(n, 0);

        int carry = 1;
        for(int i = n - 1; i >= 0; i--){
            ans[i] = digits[i] + carry;
            if(ans[i] > 9){
                carry = ans[i] / 10;
                ans[i] = ans[i] % 10;
            } else{
                carry = 0;
            }
        }

        if(carry != 0){
            ans.insert(ans.begin(), carry);
        }

        return ans;
    }
};