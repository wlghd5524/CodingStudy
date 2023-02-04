def dfs(v, cnt):
    visited[v] = True
    cnt += 1
    if v == y:
        result.append(cnt)
    for i in graph[v]:
        if not visited[i]:
            dfs(i, cnt)

n = int(input())
x, y = map(int, input().split())
m = int(input())
graph = [[] for i in range(n+1)]
visited = [False] * (n+1)
cnt = -1
result = []
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
dfs(x, cnt)
if len(result) == 0:
    print(-1)
else:
    print(result[0])
