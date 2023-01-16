day = int(input())
cnt = 0
num = map(int,input().split())
for i in num:
    if i == day:
        cnt += 1
print(cnt)