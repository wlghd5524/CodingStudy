def dfs(x, y):
    if graph[x][y] == '-':
        graph[x][y] = '0'
        if y-1 >= 0 and graph[x][y-1] == '-':
            dfs(x, y-1)
        elif y+1 < m and graph[x][y+1] == '-':
            dfs(x, y+1)
    elif graph[x][y] == '|':
        graph[x][y] = '0'
        if x-1 >= 0 and graph[x-1][y] == '|':
            dfs(x-1, y)
        elif x+1 < n and graph[x+1][y] == '|':
            dfs(x+1, y)

n, m = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(input()))
cnt = 0
for i in range(n):
    for j in range(m):
        if graph[i][j] == '|' or graph[i][j] == '-':
            dfs(i, j)
            cnt += 1
print(cnt)
