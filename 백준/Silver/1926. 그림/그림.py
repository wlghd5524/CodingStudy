import sys
sys.setrecursionlimit(10000000)

def dfs(a, b):
    graph[a][b] = 0
    global area
    area += 1
    if b-1 >= 0 and graph[a][b-1] == 1:
        dfs(a, b-1)
    if b+1 < m and graph[a][b+1] == 1:
        dfs(a, b+1)
    if a-1 >= 0 and graph[a-1][b] == 1:
        dfs(a-1, b)
    if a+1 < n and graph[a+1][b] == 1:
        dfs(a+1, b)

n, m = map(int, input().split())
graph = []
area = 0
result = [0, 0]
for i in range(n):
    graph.append(list(map(int, input().split())))
for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            dfs(i, j)
            if result[1] < area:
                result[1] = area
            area = 0
            result[0] += 1
print(result[0])
print(result[1])
