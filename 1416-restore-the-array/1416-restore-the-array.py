class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        MOD = 10 ** 9 + 7
        N = len(s)

        has_cache = [False] * (N + 1)
        cache = [None] * (N + 1)

        # total time complexity = time per input * number of input
        # index -> 0 to N
        # total number of inputs = O(N)
        # each input takes O(log K)
        # total time O(N log K)
        def count(index):
            if index == N:
                return 1
            if s[index] == "0":
                return 0
            if has_cache[index]:
                return cache[index]

            total = 0
            current = 0
            current_index = index

            while current_index < N and current <= k:
                current *= 10
                current += int(s[current_index])

                if current <= k:
                    total += count(current_index + 1)
                    total %= MOD
                else:
                    break
                current_index += 1

            has_cache[index] = True
            cache[index] = total % MOD
            return cache[index]

        return count(0)