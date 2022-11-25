# LarryNY's Code
        
class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 10 ** 9 + 7
        total = 0

        # for each number, we want to find the number of numbers that are smaller or equal to to the left
        # for each number, we want fo find the number of numbers that are strictly greater than to the right
        stack = []
        left = []
        for i, x in enumerate(arr):
            pi = i
            while len(stack) > 0 and stack[-1][1] >= x:
                pi, _ = stack.pop()

            left.append(i - pi + 1)
            stack.append((pi, x))

        stack = []
        right = []
        for i, x in enumerate(reversed(arr)):
            pi = i
            while len(stack) > 0 and stack[-1][1] > x:
                pi, _ = stack.pop()

            right.append(i - pi + 1)
            stack.append((pi, x))

        right.reverse()
        for x, L, R in zip(arr, left, right):
            total += L * R * x
            total %= MOD 

        return total % MOD        