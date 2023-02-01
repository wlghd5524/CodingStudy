n, m = map(int, input().split())
l = list(map(int, input().split()))
a = 0
b = 0
sum = l[0]
max = 0
while b < n:
    if sum >= m:
        sum -= l[a]
        a += 1
        if a == n:
            break
    elif sum < m:
        b += 1
        if b == n:
            break
        sum += l[b]
    if a > b:
        sum = l[a]
        b += 1
    if sum > max and sum <= m:
        max = sum
print(max)
