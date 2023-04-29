class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        N = len(strs)

        def calculateDelta(x, y):
            d = 0
            for a, b in zip(x, y):
                if a != b:
                    d += 1
            return d

        adj_list = collections.defaultdict(list)
        for i in range(N):
            for j in range(i + 1, N):
                if calculateDelta(strs[i], strs[j]) <= 2:
                    adj_list[i].append(j)
                    adj_list[j].append(i)

        visited = [False] * N
        count = 0

        def visit(x):
            for v in adj_list[x]:
                if not visited[v]:
                    visited[v] = True
                    visit(v)

        for i in range(N):
            if not visited[i]:
                count += 1
                visited[i] = True
                visit(i)
        
        return count