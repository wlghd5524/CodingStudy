from collections import deque


def bfs():
    global cnt
    while queue:
        a, b = queue.popleft()
        if b+1 < m and graph[a][b+1] == 0:
            queue.append([a, b+1])
            graph[a][b+1] = graph[a][b]+1
        if b-1 >= 0 and graph[a][b-1] == 0:
            queue.append([a, b-1])
            graph[a][b-1] = graph[a][b]+1
        if a+1 < n and graph[a+1][b] == 0:
            queue.append([a+1, b])
            graph[a+1][b] = graph[a][b]+1
        if a-1 >= 0 and graph[a-1][b] == 0:
            queue.append([a-1, b])
            graph[a-1][b] = graph[a][b]+1


m, n = map(int, input().split())
graph = []
queue = deque([])
result = 0
for i in range(n):
    graph.append(list(map(int, input().split())))
    for j in range(m):
        if graph[i][j] == 1:
            queue.append([i, j])
bfs()
for i in graph:
    for j in i:
        if j == 0:
            print(-1)
            exit(0)
    result = max(result, max(i))
print(result-1)
