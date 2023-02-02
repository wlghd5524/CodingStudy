import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
def dfs(a, b):
    graph[a][b] = 0
    if b-1 >= 0 and graph[a][b-1] == 1:
        dfs(a,b-1)
    if b+1 < m and graph[a][b+1] == 1:
        dfs(a,b+1)
    if a-1 >= 0 and graph[a-1][b] == 1:
        dfs(a-1,b)
    if a+1 < n and graph[a+1][b] == 1:
        dfs(a+1,b)
    
T = int(input())
for _ in range(T):
    m, n, k = map(int, input().split())
    graph = [[0 for i in range(m)] for j in range(n)]
    for i in range(k):
        x, y = map(int, input().split())
        graph[y][x] = 1
    cnt = 0
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 1:
                dfs(i, j)
                cnt += 1
    print(cnt)
