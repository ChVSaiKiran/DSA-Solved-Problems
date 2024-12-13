class Pair{
    public int value;
    public int index;

    public Pair(){
        this.value = -1;
        this.index = -1;
    }

    public Pair(int value, int index){
        this.value = value;
        this.index = index;
    }

    @Override
    public String toString(){
        return "Value: " + String.valueOf(value) + " Index: " + String.valueOf(index);
    }
}

class Solution {
    public long findScore(int[] nums) {
        int n = nums.length;
        Queue<Pair> pq = new PriorityQueue<Pair>((p1, p2) -> {
            return p1.value != p2.value ? Integer.compare(p1.value, p2.value) : Integer.compare(p1.index, p2.index);
        });

        for(int i = 0; i < n; i++){
            pq.add(new Pair(nums[i], i));
        }

        Set<Integer> vis = new HashSet<>();

        long score = 0;
        while(!pq.isEmpty()){
            Pair p = pq.poll();
            if(vis.contains(p.index)){
                continue;
            }
            score += p.value;
            vis.addAll(List.of(p.index, p.index - 1, p.index + 1));
        }

        return score;
    }
}