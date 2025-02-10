class Solution {
    public String clearDigits(String s) {
        Stack<Character> stk = new Stack<>();
        for(char ch : s.toCharArray()){
            if(ch >= '0' && ch <= '9'){
                stk.pop();
            } else{
                stk.add(ch);
            }
        }
        return stk.stream().map(c -> c.toString()).collect(Collectors.joining(""));
    }
}