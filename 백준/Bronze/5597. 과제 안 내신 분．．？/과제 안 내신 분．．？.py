list = [0] * 30
for i in range(28):
    num = int(input())
    list[num-1] = num
cnt = 0
for i in range(30):
    if list[i] == 0:
        print(i+1)
        cnt += 1
    if cnt == 2:
        break
