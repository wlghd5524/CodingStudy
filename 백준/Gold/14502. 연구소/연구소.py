from collections import deque
import copy
def wall(cnt):
    if cnt == 3:
        bfs()
        return
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                graph[i][j] = 1
                wall(cnt+1)
                graph[i][j] = 0

def bfs():
    q = deque()
    tmp_graph = copy.deepcopy(graph)
    for i in range(n):
        for j in range(m):
            if tmp_graph[i][j] == 2:
                q.append((i,j))
    while q:
        x,y = q.popleft()
        if y-1 >= 0 and tmp_graph[x][y-1] == 0:
            tmp_graph[x][y-1] = 2
            q.append((x,y-1))
        if y+1 < m and tmp_graph[x][y+1] == 0:
            tmp_graph[x][y+1] = 2
            q.append((x,y+1))
        if x-1 >= 0 and tmp_graph[x-1][y] == 0:
            tmp_graph[x-1][y] = 2
            q.append((x-1,y))
        if x+1 < n and tmp_graph[x+1][y] == 0:
            tmp_graph[x+1][y] = 2
            q.append((x+1,y))
    global result
    cnt = 0
    for i in range(n):
        cnt += tmp_graph[i].count(0)
    result = max(result,cnt)

n,m = map(int,input().split())
graph = []
result = 0
for i in range(n):
    graph.append(list(map(int,input().split())))
wall(0)
print(result)