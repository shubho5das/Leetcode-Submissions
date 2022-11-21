# LarryNY's Code

class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        R = len(maze)
        C = len(maze[0])

        sx, sy = entrance
        q = collections.deque()
        INF = 10 ** 20
        distance = [[INF] * C for _ in range(R)]

        def enqueue(x, y, d):
            distance[x][y] = d
            q.append((x, y, d))

        enqueue(sx, sy, 0)

        directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        while len(q) > 0:
            x, y, d = q.popleft()

            if x == 0 or x == R - 1 or y == 0 or y == C - 1:
                if not (x == sx and y == sy):
                    return d

            for dx, dy in directions:
                nx, ny = x + dx, y + dy

                if 0 <= nx < R and 0 <= ny < C and maze[nx][ny] != "+" and distance[nx][ny] == INF:
                    enqueue(nx, ny, d + 1)
                    if nx == 0 or nx == R - 1 or ny == 0 or ny == C - 1:
                        return d + 1

        return -1        