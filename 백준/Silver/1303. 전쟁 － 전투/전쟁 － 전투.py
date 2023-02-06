import sys
sys.setrecursionlimit(100000)

def dfs(a, b):
    team = graph[a][b]
    graph[a][b] = 'X'
    global cnt
    cnt += 1
    if b-1 >= 0 and graph[a][b-1] == team:
        dfs(a, b-1)
    if b+1 < n and graph[a][b+1] == team:
        dfs(a, b+1)
    if a-1 >= 0 and graph[a-1][b] == team:
        dfs(a-1, b)
    if a+1 < m and graph[a+1][b] == team:
        dfs(a+1, b)

n, m = map(int, input().split())
graph = []
cnt = 0
blue = 0
white = 0
team = 'X'
for i in range(m):
    graph.append(list(input()))
for i in range(m):
    for j in range(n):
        if graph[i][j] != 'X':
            if graph[i][j] == 'B':
                team = 'B'
            else:
                team = 'W'
            dfs(i, j)
            if team == 'B':
                blue += cnt*cnt
            else:
                white += cnt*cnt
            cnt = 0
print(white, blue)
