from collections import deque

def bfs():
    while q:
        a, b = q.popleft()
        if a-1 >= 0 and graph[a-1][b] == 1:
            q.append([a-1, b])
            graph[a-1][b] = graph[a][b] + 1
        if a+1 < n and graph[a+1][b] == 1:
            q.append([a+1, b])
            graph[a+1][b] = graph[a][b] + 1
        if b-1 >= 0 and graph[a][b-1] == 1:
            q.append([a, b-1])
            graph[a][b-1] = graph[a][b] + 1
        if b+1 < m and graph[a][b+1] == 1:
            q.append([a, b+1])
            graph[a][b+1] = graph[a][b] + 1

n, m = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int, input())))
q = deque()
q.append([0, 0])
bfs()
print(graph[n-1][m-1])
