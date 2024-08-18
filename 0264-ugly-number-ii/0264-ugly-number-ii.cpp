class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5};

        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> vis;

        pq.push(1);
        vis.insert(1);

        long curr;
        for(int i = 1; i <= n; i++){
            curr = pq.top();
            pq.pop();
            for(int p : primes){
                long temp = curr * p;
                if(vis.find(temp) == vis.end()){
                    pq.push(temp);
                    vis.insert(temp);
                }
            }
        }
        return (int)curr;
    }
};