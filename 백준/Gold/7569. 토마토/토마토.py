from collections import deque

def bfs():
    global cnt
    while queue:
        a, b, c = queue.popleft()
        if a+1 < h and graph[a+1][b][c] == 0:
            queue.append([a+1, b, c])
            graph[a+1][b][c] = graph[a][b][c] + 1
        if a-1 >= 0 and graph[a-1][b][c] == 0:
            queue.append([a-1, b, c])
            graph[a-1][b][c] = graph[a][b][c] + 1
        if b+1 < n and graph[a][b+1][c] == 0:
            queue.append([a, b+1, c])
            graph[a][b+1][c] = graph[a][b][c] + 1
        if b-1 >= 0 and graph[a][b-1][c] == 0:
            queue.append([a, b-1, c])
            graph[a][b-1][c] = graph[a][b][c] + 1
        if c+1 < m and graph[a][b][c+1] == 0:
            queue.append([a, b, c+1])
            graph[a][b][c+1] = graph[a][b][c] + 1
        if c-1 >= 0 and graph[a][b][c-1] == 0:
            queue.append([a, b, c-1])
            graph[a][b][c-1] = graph[a][b][c] + 1

m, n, h = map(int, input().split())
graph = [[] for i in range(h)]
queue = deque([])
result = 0
for i in range(h):
    for p in range(n):
        graph[i].append(list(map(int, input().split())))
        for j in range(m):
            if graph[i][p][j] == 1:
                queue.append([i, p, j])
bfs()
for i in graph:
    for j in i:
        for p in j:
            if p == 0:
                print(-1)
                exit(0)
        result = max(result, max(j))
print(result-1)
