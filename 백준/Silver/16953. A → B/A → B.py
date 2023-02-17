a, b = map(int, input().split())
cnt = 1
while True:
    cnt += 1
    tmp = b
    if b % 10 == 1:
        b //= 10
    elif b % 2 == 0:
        b //= 2
    if tmp == b:
        print(-1)
        exit()
    elif a == b:
        break
print(cnt)
