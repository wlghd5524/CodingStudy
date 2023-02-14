import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

def dfs(a, b):
    visited[a][b] = True
    global yes
    if a == m-1:
        yes = True
    if b-1 >= 0 and graph[a][b-1] == '0' and not visited[a][b-1]:
        dfs(a, b-1)
    if b+1 < n and graph[a][b+1] == '0' and not visited[a][b+1]:
        dfs(a, b+1)
    if a-1 >= 0 and graph[a-1][b] == '0' and not visited[a-1][b]:
        dfs(a-1, b)
    if a+1 < m and graph[a+1][b] == '0' and not visited[a+1][b]:
        dfs(a+1, b)

m, n = map(int, input().split())
graph = []
visited = [[False]*n for i in range(m)]
tmp = visited
yes = False
for i in range(m):
    graph.append(list(input()))
for i in range(n):
    dfs(0, i)
    visited = tmp
if yes:
    print("YES")
else:
    print("NO")
