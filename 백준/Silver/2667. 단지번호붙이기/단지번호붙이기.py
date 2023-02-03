def dfs(a, b):
    graph[a][b] = 0
    global house_cnt
    house_cnt += 1
    if b+1 < n and graph[a][b+1] == 1:
        dfs(a, b+1)
    if b-1 >= 0 and graph[a][b-1] == 1:
        dfs(a, b-1)
    if a+1 < n and graph[a+1][b] == 1:
        dfs(a+1, b)
    if a-1 >= 0 and graph[a-1][b] == 1:
        dfs(a-1, b)


n = int(input())
graph = []
for i in range(n):
    graph.append(list(map(int, input())))
cnt = 0
house_cnt = 0
house = []
for i in range(n):
    for j in range(n):
        if graph[i][j] == 1:
            dfs(i, j)
            cnt += 1
            house.append(house_cnt)
            house_cnt = 0
print(cnt)
house.sort()
for i in house:
    print(i)
