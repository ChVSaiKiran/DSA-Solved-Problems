class Solution {
    public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
        List<List<Integer>> ans = new ArrayList<>();
        if(Arrays.stream(colsum).sum() != upper + lower){
            return ans;
        }
        int n = colsum.length;
        
        List<Integer> innerList = new ArrayList<>(Collections.nCopies(n, 0));
        ans.add(new ArrayList<>(innerList));
        ans.add(new ArrayList<>(innerList));

        for(int i = 0; i < n; i++){
            if(colsum[i] == 0){
                continue;
            } else if(colsum[i] == 2){
                if(upper == 0 || lower == 0){
                    return new ArrayList<>();
                } else{
                    ans.get(0).set(i, 1);
                    ans.get(1).set(i, 1);
                    upper--;
                    lower--;
                }
            } else{
                if(upper >= lower && upper != 0){
                    ans.get(0).set(i, 1);
                    upper--;
                } else if(lower >= upper && lower != 0){
                    ans.get(1).set(i, 1);
                    lower--;
                } else{
                    return new ArrayList<>();
                }
            }
        }

        return ans;
    }
}