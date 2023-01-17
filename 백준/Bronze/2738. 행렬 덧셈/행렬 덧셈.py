n, m = map(int, input().split())
l = [[]*m]*n
for i in range(n):
    l[i] = list(map(int, input().split()))
for i in range(n):
    num = list(map(int, input().split()))
    for j in range(m):
        l[i][j] += num[j]
for i in range(n):
    for j in range(m):
        print(l[i][j], end=" ")
    print("")
