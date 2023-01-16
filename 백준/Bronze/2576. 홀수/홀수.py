sum = 0
min = 100
for i in range(0, 7):
    num = int(input())
    if num % 2 == 1:
        sum += num
        if num < min:
            min = num
if sum == 0:
    print(-1)
else:
    print(sum)
    print(min)
