from collections import defaultdict
t = int(input())
for i in range(t):
    n = int(input())
    dic = defaultdict(list)
    for i in range(n):
        a, b = map(str, input().split())
        dic[b].append(a)
    sum = 1
    for i in dic:
        sum *= len(dic[i])+1
    print(sum-1)
