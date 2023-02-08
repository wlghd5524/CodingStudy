import sys
sys.setrecursionlimit(100000)

def dfs(a, b):
    graph[a][b] = 0
    if b-1 >= 0:
        if graph[a][b-1] == 1:
            dfs(a, b-1)
        if a-1 >= 0 and graph[a-1][b-1] == 1:
            dfs(a-1, b-1)
        if a+1 < m and graph[a+1][b-1] == 1:
            dfs(a+1, b-1)
    if b+1 < n:
        if graph[a][b+1] == 1:
            dfs(a, b+1)
        if a-1 >= 0 and graph[a-1][b+1] == 1:
            dfs(a-1, b+1)
        if a+1 < m and graph[a+1][b+1] == 1:
            dfs(a+1, b+1)
    if a-1 >= 0 and graph[a-1][b] == 1:
        dfs(a-1, b)
    if a+1 < m and graph[a+1][b] == 1:
        dfs(a+1, b)

m, n = map(int, input().split())
graph = []
cnt = 0
for i in range(m):
    graph.append(list(map(int, input().split())))
for i in range(m):
    for j in range(n):
        if graph[i][j] == 1:
            dfs(i, j)
            cnt += 1
print(cnt)
