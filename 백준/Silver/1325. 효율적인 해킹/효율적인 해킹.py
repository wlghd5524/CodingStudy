import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(100000)

def dfs(v):
    global cnt
    cnt += 1
    visited[v] = True
    for i in graph[v]:
        if not visited[i]:
            dfs(i)

def bfs(v):
    visited[v] = True
    q = deque()
    q.append(v)
    global cnt
    while q:
        v = q.popleft()
        for i in graph[v]:
            if not visited[i]:
                q.append(i)
                visited[i] = True
                cnt += 1

n, m = map(int, input().split())
graph = [[] for i in range(n+1)]
visited = [False for i in range(n+1)]
tmp = visited[:]
max = 0
result = []
for i in range(m):
    x, y = map(int, input().split())
    graph[y].append(x)
for i in range(1, n+1):
    cnt = 0
    visited = tmp[:]
    bfs(i)
    if cnt > max:
        max = cnt
        result.clear()
        result.append(i)
    elif cnt == max:
        result.append(i)
print(*result)
