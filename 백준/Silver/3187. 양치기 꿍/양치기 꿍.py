import sys
sys.setrecursionlimit(100000)

def dfs(a, b):
    global sheep
    global wolf
    if graph[a][b] == 'k':
        sheep += 1
    elif graph[a][b] == 'v':
        wolf += 1
    graph[a][b] = '#'
    if b-1 >= 0 and graph[a][b-1] != '#':
        dfs(a, b-1)
    if b+1 < c and graph[a][b+1] != '#':
        dfs(a, b+1)
    if a-1 >= 0 and graph[a-1][b] != '#':
        dfs(a-1, b)
    if a+1 < r and graph[a+1][b] != '#':
        dfs(a+1, b)

r, c = map(int, input().split())
graph = []
wolf = 0
sheep = 0
wolf_sum = 0
sheep_sum = 0
for i in range(r):
    graph.append(list(input()))
for i in range(r):
    for j in range(c):
        if graph[i][j] != '#':
            dfs(i, j)
            if wolf < sheep:
                sheep_sum += sheep
            else:
                wolf_sum += wolf
            sheep = 0
            wolf = 0
print(sheep_sum, wolf_sum)
