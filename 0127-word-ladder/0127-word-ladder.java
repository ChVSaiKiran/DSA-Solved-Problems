class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        HashSet<String> s = new HashSet<>();
        for(String i:wordList)
            s.add(i);
        Queue<String> q = new LinkedList<>();
        q.add(beginWord);
        int cnt = 1;
        while(!q.isEmpty()){
            cnt++;
            int n = q.size();
            while(n != 0){
                String u = q.remove();
                for(int i = 0; i < u.length(); i++)
                    for(char j = 'a'; j <= 'z'; j++){
                        String v = u.substring(0, i) + j + u.substring(i + 1);
                        if(s.contains(v)){
                            if(endWord.equals(v))
                                return cnt;
                            s.remove(v);
                            q.add(v);
                        }
                    }
                n--;
            }
        }
        return 0;
    }
}