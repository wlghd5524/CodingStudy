import sys
sys.setrecursionlimit(10000000)

def dfs(a, b):
    visited[a][b] = 1
    if b+1 < n and visited[a][b+1] == 0 and h < graph[a][b+1]:
        dfs(a, b+1)
    if b-1 >= 0 and visited[a][b-1] == 0 and h < graph[a][b-1]:
        dfs(a, b-1)
    if a+1 < n and visited[a+1][b] == 0 and h < graph[a+1][b]:
        dfs(a+1, b)
    if a-1 >= 0 and visited[a-1][b] == 0 and h < graph[a-1][b]:
        dfs(a-1, b)

n = int(input())
graph = []
h_max = 0
result = 0
cnt = 0
for i in range(n):
    graph.append(list(map(int, input().split())))
    if h_max < max(graph[i]):
        h_max = max(graph[i])
for h in range(h_max):
    visited = [[0]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            if visited[i][j] == 0 and graph[i][j] > h:
                dfs(i, j)
                cnt += 1
    if result < cnt:
        result = cnt
    cnt = 0
print(result)
