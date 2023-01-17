import sys
t = int(input())
for i in range(0, t):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    print(a+b)
