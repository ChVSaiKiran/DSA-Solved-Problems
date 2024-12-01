class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> st = new HashSet<>();
        for(int i : arr){
            if(st.contains(i)){
                return true;
            }
            st.add(i * 2);
            if(i % 2 == 0)
            st.add(i / 2);
        }
        return false;
    }
}