# LarrryNY's Code

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        N = len(nums)
    
        lookup = []
        ans = 0

        for i in range(N):
            lookup.append(collections.defaultdict(int))

            for j in range(i):
                delta = nums[i] - nums[j]

                if delta in lookup[j]:
                    count = lookup[j][delta]
                    ans += count
                    lookup[i][delta] += count + 1
                else:
                    lookup[i][delta] += 1

        return ans        