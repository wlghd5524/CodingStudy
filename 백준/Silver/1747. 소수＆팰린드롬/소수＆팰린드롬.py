import math
def is_prime_number(x):
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True

n = int(input())
while True:
    if is_prime_number(n) and n >= 2:
        tmp = str(n)
        a = 0
        b = len(tmp)-1
        is_right = True
        while a<=len(tmp)/2:
            if tmp[a] != tmp[b]:
                is_right = False
                break
            a+=1
            b-=1
        if is_right:
            print(n)
            break
    n+=1