class Solution:
    def findAnswer(self, parent: List[int], s: str) -> List[bool]:
        adj = defaultdict(list)
        root = -1
        for i, p in enumerate(parent):
            if p == -1:
                root = i
            else:
                adj[p].append(i)
        
        n = len(parent)
        res = [False] * n
        def dfs(u):
            temp = ""
            for v in adj[u]:
                temp += dfs(v)
            temp += s[u]
            res[u] = temp == temp[::-1]
            return temp
        dfs(root)

        return res
