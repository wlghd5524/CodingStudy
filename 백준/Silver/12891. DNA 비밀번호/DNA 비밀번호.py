def dna_check(ch):
    if ch == 'A':
        return 0
    elif ch == 'C':
        return 1
    elif ch == 'G':
        return 2
    elif ch == 'T':
        return 3

s, p = map(int, input().split())
st = input()
need = list(map(int, input().split()))
a = 0
b = p-1
result = 0
cnt = [0] * 4
for i in range(a, b+1):
    cnt[dna_check(st[i])] += 1
while 1:
    if need[0] <= cnt[0] and need[1] <= cnt[1] and need[2] <= cnt[2] and need[3] <= cnt[3]:
        result += 1
    b += 1
    if b == len(st):
        break
    cnt[dna_check(st[b])] += 1
    cnt[dna_check(st[a])] -= 1
    a += 1
print(result)
