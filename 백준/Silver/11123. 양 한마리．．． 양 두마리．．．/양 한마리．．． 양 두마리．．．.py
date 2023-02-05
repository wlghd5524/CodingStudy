import sys
sys.setrecursionlimit(100000)

def dfs(a, b):
    graph[a][b] = '.'
    if b-1 >= 0 and graph[a][b-1] == '#':
        dfs(a, b-1)
    if b+1 < w and graph[a][b+1] == '#':
        dfs(a, b+1)
    if a-1 >= 0 and graph[a-1][b] == '#':
        dfs(a-1, b)
    if a+1 < h and graph[a+1][b] == '#':
        dfs(a+1, b)

T = int(input())
for _ in range(T):
    h, w = map(int, input().split())
    graph = []
    cnt = 0
    for i in range(h):
        graph.append(list(input()))
    for i in range(h):
        for j in range(w):
            if graph[i][j] == '#':
                dfs(i, j)
                cnt += 1
    print(cnt)
