## LarryNY's Code
#  (will solve by my own - after completing the current Internship Work)

class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        N = len(colors)

        adj_list = collections.defaultdict(list)
        for u, v in edges:
            adj_list[u].append(v)

        # Determine whether there's a cycle
        BLACK = 0
        GRAY = 1
        WHITE = 2
        visited_colors = [WHITE] * N

        def has_cycle(index):
            visited_colors[index] = GRAY
            for v in adj_list[index]:
                if visited_colors[v] == GRAY:
                    return True
                if visited_colors[v] == WHITE and has_cycle(v):
                    return True

            visited_colors[index] = BLACK
            return False

        for i in range(N):
            if visited_colors[i] == WHITE:
                if has_cycle(i):
                    return -1

        def calculate(color):
            cache = [None] * N
            has_cache = [False] * N

            # index -> 0 to N
            # O(N) number of inputs
            # O(V + E) total amortized
            def get_longest(index):
                if has_cache[index]:
                    return cache[index]

                current = 0
                if colors[index] == color:
                    current = 1

                best = 0
                for v in adj_list[index]:
                    best = max(best, get_longest(v))
                best += current
                has_cache[index] = True
                cache[index] = best
                return best
            
            best = 0
            for i in range(N):
                best = max(best, get_longest(i))
            return best

        best = 0
        # No cycles in this graph
        for c in set(colors):
            best = max(best, calculate(c))
        return best        