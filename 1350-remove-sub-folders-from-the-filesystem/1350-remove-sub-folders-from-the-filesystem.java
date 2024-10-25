class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Set<String> inp = new HashSet<>(Set.of(folder));
        List<String> res = new ArrayList<>();
        Arrays.stream(folder).forEach(s -> {
            char arr[] = s.toCharArray();
            StringBuilder sb = new StringBuilder();
            boolean flag = true;
            for(char i : arr){
                if(i == '/' && inp.contains(sb.toString())){
                    flag = false;
                    break;
                }
                sb.append(i);
            }
            if(flag){
                res.add(s);
            }
        });
        return res;
    }
}