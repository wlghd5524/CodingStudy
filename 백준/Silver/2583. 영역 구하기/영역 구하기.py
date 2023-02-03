import sys
sys.setrecursionlimit(10000000)

def dfs(a, b):
    graph[a][b] = 1
    global area
    area += 1
    if b+1 < n and graph[a][b+1] == 0:
        dfs(a, b+1)
    if b-1 >= 0 and graph[a][b-1] == 0:
        dfs(a, b-1)
    if a+1 < m and graph[a+1][b] == 0:
        dfs(a+1, b)
    if a-1 >= 0 and graph[a-1][b] == 0:
        dfs(a-1, b)

m, n, k = map(int, input().split())
graph = [[0]*n for i in range(m)]
for _ in range(k):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(y1-m, y2-m):
        for j in range(x1, x2):
            graph[i][j] = 1
cnt = 0
area = 0
l = []
for i in range(m):
    for j in range(n):
        if graph[i][j] == 0:
            dfs(i, j)
            cnt += 1
            l.append(area)
            area = 0
print(cnt)
l.sort()
print(*l)
