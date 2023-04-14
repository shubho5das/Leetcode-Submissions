# LarryNY's Code
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        N = len(pushed)

        i = j = 0

        stack = []
        while i < N:
            stack.append(pushed[i])

            while len(stack) > 0 and popped[j] == stack[-1]:
                stack.pop()
                j += 1

            i += 1

        return len(stack) == 0