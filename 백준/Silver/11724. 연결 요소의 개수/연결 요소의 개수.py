import sys
sys.setrecursionlimit(5000)
input = sys.stdin.readline
def dfs(cur, depth):
    visited[cur] = True
    for i in graph[cur]:
        if not visited[i]:
            dfs(i, depth+1)

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
visited = [False] * (n+1)
result = 0
for i in range(1, n+1):
    if not visited[i]:
        if not graph[i]:
            result += 1
            visited[i] = True
        else:
            dfs(i, 0)
            result += 1
print(result)
