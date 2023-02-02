import sys
sys.setrecursionlimit(100000)
def dfs(a, b):
    graph[a][b] = 0
    if b-1 >= 0:
        if graph[a][b-1] == 1:
            dfs(a, b-1)
        if a-1 >= 0 and graph[a-1][b-1] == 1:
            dfs(a-1, b-1)
        if a+1 < h and graph[a+1][b-1] == 1:
            dfs(a+1, b-1)
    if b+1 < w:
        if graph[a][b+1] == 1:
            dfs(a, b+1)
        if a-1 >= 0 and graph[a-1][b+1] == 1:
            dfs(a-1, b+1)
        if a+1 < h and graph[a+1][b+1] == 1:
            dfs(a+1, b+1)
    if a-1 >= 0 and graph[a-1][b] == 1:
        dfs(a-1, b)
    if a+1 < h and graph[a+1][b] == 1:
        dfs(a+1, b)


while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    graph = []
    for i in range(h):
        graph.append(list(map(int, input().split())))
    cnt = 0
    for i in range(h):
        for j in range(w):
            if graph[i][j] == 1:
                dfs(i, j)
                cnt += 1
    print(cnt)
