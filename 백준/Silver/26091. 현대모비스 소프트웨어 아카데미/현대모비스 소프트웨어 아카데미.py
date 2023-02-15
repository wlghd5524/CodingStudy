n, m = map(int, input().split())
member = list(map(int, input().split()))
member.sort()
result = 0
a = 0
b = n-1
while a < b:
    if member[a] + member[b] >= m:
        result += 1
    a += 1
    b -= 1
print(result)