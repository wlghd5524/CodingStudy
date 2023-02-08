def dfs(v, cnt):
    visited[v] = True
    if cnt == 4:
        print(1)
        exit()
    for i in graph[v]:
        if not visited[i]:
            dfs(i, cnt+1)
            visited[i] = False

n, m = map(int, input().split())
graph = [[]for i in range(n)]
visited = [False for i in range(n)]
for i in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)
for i in range(n):
    if not visited[i]:
        dfs(i, 0)
        visited[i] = False
print(0)
