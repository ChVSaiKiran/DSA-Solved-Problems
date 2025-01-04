class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;

        Stack<Integer> s = new Stack<>();
        HashMap<Integer, Integer> mp = new HashMap<>();

        for(int i = n2 - 1; i >= 0; i--){
            while(!s.isEmpty() && s.peek() <= nums2[i]){
                s.pop();
            }
            mp.put(nums2[i], (s.isEmpty() ? -1 : s.peek()));
            s.add(nums2[i]);
        }

        int ans[] = new int[n1];
        for(int i = 0; i < n1; i++){
            ans[i] = mp.get(nums1[i]);
        }
        
        return ans;
    }
}