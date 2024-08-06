class Solution {
    public int minimumPushes(String word) {
        HashMap<Character, Integer> map = new HashMap<>();
        for(char i : word.toCharArray()){
            map.put(i, map.getOrDefault(i, 0) + 1);
        }

        int cnt = 8, ans = 0;
        List<Integer> values = new ArrayList<>(map.values());
        Collections.sort(values, Collections.reverseOrder());

        for(int i : values){
            ans += i * (int)(cnt / 8);
            cnt++;
        };

        return ans;
    }
}