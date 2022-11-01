class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m = len(grid)
        n = len(grid[0])
        res = [i for i in range(n)]
        
        for i in grid:
            for j, val in enumerate(res):
                if val!=(-1):
                    if (val + i[val])%(n+1) == n:
                        res[j] = -1
                    elif i[val]!=i[val+i[val]]:
                        res[j] = -1
                    else:
                        res[j] = val + i[val]
        
        return res