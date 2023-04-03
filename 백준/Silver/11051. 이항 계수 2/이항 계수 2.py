n, k = map(int, input().split())
result = 1
for i in range(k):
    result *= n-i
for i in range(1, k+1):
    result //= i
print(int(result % 10007))
