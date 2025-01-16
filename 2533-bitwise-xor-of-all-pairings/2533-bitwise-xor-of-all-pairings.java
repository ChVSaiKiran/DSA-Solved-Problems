class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        if((n % 2 == 0) && (m % 2 == 0)){
            return 0;
        }

        int xor1 = Arrays.stream(nums1).reduce(0, (a, b) -> a ^ b);
        int xor2 = Arrays.stream(nums2).reduce(0, (a, b) -> a ^ b);

        if((n % 2 == 1) && (m % 2 == 1)){
            return xor1 ^ xor2;
        }

        return (n % 2 == 0) ? xor1 : xor2;
    }
}