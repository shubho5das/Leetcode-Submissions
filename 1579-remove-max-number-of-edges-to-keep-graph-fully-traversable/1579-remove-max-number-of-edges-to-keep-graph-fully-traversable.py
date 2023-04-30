class UnionFind:
    def __init__(self, N):
        self.parents = [x for x in range(N)]
        self.N = N

    def ufind(self, x):
        if self.parents[x] != x:
            self.parents[x] = self.ufind(self.parents[x])
        return self.parents[x]

    def uunion(self, a, b):
        ua = self.ufind(a)
        ub = self.ufind(b)

        self.parents[ua] = ub

class Solution:
    def maxNumEdgesToRemove(self, N: int, edges: List[List[int]]) -> int:
        # Union-Find
        ufa = UnionFind(N)
        ufb = UnionFind(N)
        keep = 0

        for t, u, v in edges:
            u -= 1
            v -= 1
            if t == 3:
                if ufa.ufind(u) != ufa.ufind(v):
                    ufa.uunion(u, v)
                    ufb.uunion(u, v)
                    keep += 1
                
        for t, u, v in edges:
            u -= 1
            v -= 1
            if t == 1:
                if ufa.ufind(u) != ufa.ufind(v):
                    ufa.uunion(u, v)
                    keep += 1
            if t == 2:
                if ufb.ufind(u) != ufb.ufind(v):
                    ufb.uunion(u, v)
                    keep += 1
        
        for i in range(1, N):
            if ufa.ufind(i) != ufa.ufind(0):
                return -1
            if ufb.ufind(i) != ufb.ufind(0):
                return -1

        return len(edges) - keep
