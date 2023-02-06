import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

def dfs(v):
    visited[v] = True
    global cnt
    cnt += 1
    for i in graph[v]:
        if not visited[i]:
            dfs(i)

n,m = map(int,input().split())
graph = [[] for i in range(n+1)]
visited = [False] * (n+1)
cnt = 0
result = []
for i in range(m):
    x,y = map(int,input().split())
    graph[y].append(x)
k = int(input())
dfs(k)
print(cnt-1)