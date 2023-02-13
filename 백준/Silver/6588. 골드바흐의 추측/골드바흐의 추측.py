import sys
input = sys.stdin.readline

def is_prime_number(x):
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True

l = []
while True:
    n = int(input())
    if n == 0:
        break
    l.append(n)
m = max(l)
is_prime = [False for i in range(m+1)]
for i in range(2, m+1):
    if is_prime_number(i):
        is_prime[i] = True
for i in l:
    a = 2
    b = i-2
    while True:
        if is_prime[a] and is_prime[b]:
            print(str(i) + " = " + str(a) + " + " + str(b))
            break
        a += 1
        b -= 1
