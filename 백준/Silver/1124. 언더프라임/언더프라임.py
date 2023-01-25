import math

def is_prime_number(x):
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True

a, b = map(int, input().split())
cnt = 0
for i in range(a, b+1):
    l = []
    for j in range(2, int(i ** 0.5)+1):
        while i % j == 0:
            l.append(j)
            i //= j
    if i > 1:
        l.append(i)
    if is_prime_number(len(l)) and len(l) >= 2:
        cnt += 1
print(cnt)
