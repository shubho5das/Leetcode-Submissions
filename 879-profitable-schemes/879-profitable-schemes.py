# LarryNY's Code
class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        MOD = 10 ** 9 + 7
        G = len(group)

        has_cache = [[[False] * (minProfit + 1) for _ in range(G + 1)] for _ in range(n + 1)]
        cache = [[[None] * (minProfit + 1) for _ in range(G + 1)] for _ in range(n + 1)]

        # total time complexity = time per input * number of inputs
        # people_left -> 0 to N
        # index -> 0 to G
        # profit_left -> 0 to minProfit -> 100
        # number of inputs = 100^3 = 1 million
        # each input has to take O(1) time
        def count(people_left, index, profit_left):
            if people_left < 0:
                return 0
            if profit_left < 0:
                profit_left = 0

            if index == G:
                if profit_left == 0:
                    return 1
                return 0

            if has_cache[people_left][index][profit_left]:
                return cache[people_left][index][profit_left]

            # given scheme "index" - we either "use" this scheme, or not
            nums_using_scheme = count(people_left - group[index], index + 1, profit_left - profit[index])
            nums_not_using_scheme = count(people_left, index + 1, profit_left)

            has_cache[people_left][index][profit_left] = True
            cache[people_left][index][profit_left] = (nums_using_scheme + nums_not_using_scheme) % MOD
            return cache[people_left][index][profit_left]

        return count(n, 0, minProfit) % MOD        