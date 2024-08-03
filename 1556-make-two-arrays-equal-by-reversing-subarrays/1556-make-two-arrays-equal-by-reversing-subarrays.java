class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        int temp[] = new int[1001];
        Arrays.stream(target).forEach(i -> temp[i]++);
        Arrays.stream(arr).forEach(i -> temp[i]--);
        return Arrays.stream(temp).filter(i -> i != 0).count() == 0;
    }
}