N = int(input())
a = input()
bit = [0] * 26
x = 0
y = 0
max = 0
cnt = 1
bit[ord(a[0])-97] = 1
while True:
    if cnt <= N:
        y += 1
        if y == len(a):
            break
        bit[ord(a[y])-97] += 1
    elif cnt > N:
        bit[ord(a[x])-97] -= 1
        x += 1
    cnt = 26 - bit.count(0)
    if max < y-x+1 and cnt <= N:
        max = y-x+1
print(max)
