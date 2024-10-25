class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Set<String> inp = new HashSet<>(Set.of(folder));
        return Arrays.stream(folder).filter(s -> {
                    StringBuilder sb = new StringBuilder();
                    for(char i : s.toCharArray()){
                        if(i == '/' && inp.contains(sb.toString())){
                            return false;
                        }
                        sb.append(i);
                    }
                    return true;
                }).collect(Collectors.toList());
    }
}