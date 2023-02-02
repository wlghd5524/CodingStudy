import sys
sys.setrecursionlimit(10000)

def dfs1(a,b):
    if not visited[a][b]:
        visited[a][b] = True
        ch = graph[a][b]
        if b+1 < n and graph[a][b+1] == ch:
            dfs1(a,b+1)
        if b-1 >= 0 and graph[a][b-1] == ch:
            dfs1(a,b-1)
        if a+1 < n and graph[a+1][b] == ch:
            dfs1(a+1,b)
        if a-1 >= 0 and graph[a-1][b] == ch:
            dfs1(a-1,b)

def dfs2(a,b):
    if not visited[a][b]:
        visited[a][b] = True
        ch = graph[a][b]
        if ch == 'R' or ch == 'G':
            if b+1 < n and (graph[a][b+1] == 'R' or graph[a][b+1] == 'G'):
                dfs2(a,b+1)
            if b-1 >= 0 and (graph[a][b-1] == 'R' or graph[a][b-1] == 'G'): 
                dfs2(a,b-1)
            if a+1 < n and (graph[a+1][b] == 'R' or graph[a+1][b] == 'G'):
                dfs2(a+1,b)
            if a-1 >= 0 and (graph[a-1][b] == 'R' or graph[a-1][b]=='G'):
                dfs2(a-1,b)
        else:
            if b+1 < n and graph[a][b+1] == ch:
                dfs2(a,b+1)
            if b-1 >= 0 and graph[a][b-1] == ch:
                dfs2(a,b-1)
            if a+1 < n and graph[a+1][b] == ch:
                dfs2(a+1,b)
            if a-1 >= 0 and graph[a-1][b] == ch:
                dfs2(a-1,b)

n = int(input())
visited = [[False for i in range(n)] for j in range(n)]
graph = []
for i in range(n):
    graph.append(list(input()))
cnt1 = 0
cnt2 = 0
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            dfs1(i,j)
            cnt1 += 1
visited = [[False for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            dfs2(i,j)
            cnt2 += 1
print(cnt1,cnt2)