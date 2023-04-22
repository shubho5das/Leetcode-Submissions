class Solution:
    def minInsertions(self, s: str) -> int:
        N = len(s)
        INF = 10 ** 20

        has_cache = [[False] * N for _ in range(N)]
        cache = [[None] * N for _ in range(N)]

        # inclusive bounds
        # left -> 0 to N
        # right -> 0 to N
        # O(N^2) -> each input takes O(1) time
        def getMin(left, right):
            if left == right:
                return 0
            if left > right:
                return 0

            if has_cache[left][right]:
                return cache[left][right]

            best = INF            
            if s[left] == s[right]:
                best = min(best, getMin(left + 1, right - 1))

            best = min(best, getMin(left + 1, right) + 1)
            best = min(best, getMin(left, right - 1) + 1)

            has_cache[left][right] = True
            cache[left][right] = best
            return best

        return getMin(0, N - 1)