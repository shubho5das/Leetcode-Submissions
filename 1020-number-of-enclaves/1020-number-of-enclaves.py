# LarryNY's Code
class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])

        used = [[False] * C for _ in range(R)]
        directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        def bfs(x, y):
            q = collections.deque()

            def enqueue(x, y):
                used[x][y] = True
                q.append((x, y))

            count = 0
            enqueue(x, y)
            reached = False

            while len(q) > 0:
                cx, cy = q.popleft()
                count += 1

                for dx, dy in directions:
                    nx, ny = cx + dx, cy + dy

                    if 0 <= nx < R and 0 <= ny < C:
                        if not used[nx][ny] and grid[nx][ny] == 1:
                            enqueue(nx, ny)
                    else:
                        reached = True
            
            if reached:
                return 0
            return count

        area = 0
        for x in range(R):
            for y in range(C):
                if not used[x][y] and grid[x][y] == 1:
                    area += bfs(x, y)
        return area