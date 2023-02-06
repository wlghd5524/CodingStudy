import sys
sys.setrecursionlimit(100000)

def dfs(a, b):
    graph[a][b] = 0
    global cnt
    cnt += 1
    if b-1 >= 0 and graph[a][b-1] == 1:
        dfs(a, b-1)
    if b+1 < m and graph[a][b+1] == 1:
        dfs(a, b+1)
    if a-1 >= 0 and graph[a-1][b] == 1:
        dfs(a-1, b)
    if a+1 < n and graph[a+1][b] == 1:
        dfs(a+1, b)

n, m, k = map(int, input().split())
graph = [[0]*m for i in range(n)]
result = 0
cnt = 0
for i in range(k):
    r, c = map(int, input().split())
    graph[r-1][c-1] = 1
for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            dfs(i, j)
            if result < cnt:
                result = cnt
            cnt = 0
print(result)
