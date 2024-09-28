struct DisjointSet{
public:
	vector<int> par, size;
	DisjointSet(int n){
		par.resize(n + 1);
		size.resize(n + 1, 1);
		for(int i = 0; i <= n; i++){
			par[i] = i;
        }
	}

	int getParent(int node){
		if(node == par[node]){
			return node;
		}
		return par[node] = getParent(par[node]);
	}

	void unionBySize(int u, int v){
		int pu = getParent(u);
		int pv = getParent(v);

		if(pu == pv){
			return;
		}

		if (size[pu] < size[pv]) {
            par[pu] = pv;
            size[pv] += size[pu];
        } else {
            par[pv] = pu;
            size[pu] += size[pv];
        }
	}
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        DisjointSet obj(n * n);

        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(grid[x][y] == 0) continue;

                int idx = ((x * n) + y); obj.size[idx] = 1;
                for(int i = 0; i < 4; i++){
                    int dx = x + delRow[i];
                    int dy = y + delCol[i];
                    if(dx >= 0 && dy >= 0 && dx < n && dy < n && grid[dx][dy] == 1){
                        int nIdx = ((dx * n) + dy);
                        obj.unionBySize(idx, nIdx);
                    }
                }
            }
        }
       
        int maxPossible = 0;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(grid[x][y] == 1) continue;

                set<int> st;
                for(int i = 0; i < 4; i++){
                    int dx = x + delRow[i];
                    int dy = y + delCol[i];
                    if(dx >= 0 && dy >= 0 && dx < n && dy < n && grid[dx][dy] == 1){
                        int idx = ((dx * n) + dy);
                        st.insert(obj.getParent(idx));
                    }
                }

                int possible = 1;
                for(int root : st){
                    possible += obj.size[root];
                }

                maxPossible = max(maxPossible, possible);
            }
        }

        for (int i = 0; i < n * n; i++) {
            maxPossible = max(maxPossible, obj.size[obj.getParent(i)]);
        }

        return maxPossible;
    }
};