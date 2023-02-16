def dfs(v):
    graph[v] = -2
    for i in range(n):
        if v == graph[i]:
            dfs(i)

n = int(input())
graph = list(map(int, input().split()))
rm = int(input())
cnt = 0
dfs(rm)
for i in range(n):
    if graph[i] != -2 and i not in graph:
        cnt += 1
print(cnt)
