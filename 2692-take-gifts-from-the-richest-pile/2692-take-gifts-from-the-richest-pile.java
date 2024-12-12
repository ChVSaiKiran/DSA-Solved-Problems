class Solution {
    public long pickGifts(int[] gifts, int k) {
        Queue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        pq.addAll(Arrays.stream(gifts).boxed().collect(Collectors.toList()));

        while(k-- > 0){
            pq.add((int)Math.floor(Math.sqrt(pq.poll())));
        }

        return pq.stream().mapToLong(Integer::longValue).sum();        
    }
}