class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int freq[] = new int[26];
        Arrays.fill(freq, 0);

        for(char ch : s.toCharArray()){
            freq[ch - 'a']++;
        }

        int prev = 26;
        StringBuffer sb = new StringBuffer();

        while(true){
            int i = 25, flag = 0;
            // System.out.println((char)('a' + prev));
            for(i = 25; i >= 0; i--){
                if(freq[i] > 0 && i != prev){
                    int cnt = 1;
                    while(cnt <= repeatLimit && freq[i] > 0){
                        sb.append((char)('a' + i));
                        cnt++; freq[i]--;
                        if(flag == 1){
                            break;
                        }
                    }
                    prev = i;
                    // System.out.println(cnt);
                    break;
                } else if(freq[i] > 0){
                    flag = 1;
                }
            }
            if(i == -1){
                break;
            }
        }

        return sb.toString();
    }
}