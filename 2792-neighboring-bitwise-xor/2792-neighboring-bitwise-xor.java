class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int n = derived.length;

        int prefix[] = new int[n];
        prefix[0] = derived[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] ^ derived[i];
        }

        if(prefix[n - 1] != 0){
            return false;
        }

        int suffix[] = new int[n];
        suffix[n - 1] = derived[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = suffix[i + 1] ^ derived[i];
        }

        if(suffix[0] != 0){
            return false;
        }

        for(int i = 0; i < n - 1; i++){
            if(prefix[i] != suffix[i + 1]){
                return false;
            }
        }

        return true;
    }
}