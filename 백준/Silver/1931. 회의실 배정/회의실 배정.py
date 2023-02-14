import sys
input = sys.stdin.readline
n = int(input())
l = []
m = 0
for i in range(n):
    l.append(list(map(int, input().split())))
    if m < l[i][1]:
        m = l[i][1]
used = [False for i in range(m)]
l.sort(key=lambda x: (x[1], x[0]))
cnt = 0
end = 0
for i in l:
    if i[0] >= end:
        cnt += 1
        end = i[1]
print(cnt)
