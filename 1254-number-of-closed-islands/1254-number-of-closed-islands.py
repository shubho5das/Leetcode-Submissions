# LarryNY's Code
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])

        used = [[False] * C for _ in range(R)]

        directions = [(1, 0), (-1, 0), (0, -1), (0, 1)]

        def traverse_island(x, y):
            if used[x][y]:
                return
            used[x][y] = True

            for dx, dy in directions:
                nx, ny = x + dx, y + dy

                if 0 <= nx < R and 0 <= ny < C:
                    if grid[nx][ny] == 0:
                        traverse_island(nx, ny)
                else:
                    nonlocal closed
                    closed = False

        islands = 0
        for x in range(R):
            for y in range(C):
                if not used[x][y] and grid[x][y] == 0:
                    closed = True
                    traverse_island(x, y)
                    if closed:
                        islands += 1
        return islands        