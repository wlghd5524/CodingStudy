max = 0
sum = 0
for i in range(4):
    a, b = map(int, input().split())
    sum -= a
    sum += b
    if sum > max:
        max = sum
print(max)
