import sys
input = sys.stdin.readline

def is_prime_number(x):
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True

while True:
    n = int(input())
    if n == 0:
        break
    a = 2
    b = n-2
    while True:
        if is_prime_number(a) and is_prime_number(b):
            print(str(n) + " = " + str(a) + " + " + str(b))
            break
        a += 1
        b -= 1
