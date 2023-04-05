## Larry NY's Code 
#  Will solve on my own tomorrow

class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        N = len(nums)

        area = 0
        best = 0
        for i in range(N):
            area += nums[i]

            best = max(best, (area + i) // (i + 1))
        return best

                