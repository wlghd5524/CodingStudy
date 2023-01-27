N = input()
yes = False
for i in range(1, len(N)):
    a = N[0:i]
    b = N[i:]
    sum_a = 1
    sum_b = 1
    for i in a:
        sum_a *= int(i)
    for i in b:
        sum_b *= int(i)
    if sum_a == sum_b:
        yes = True
        break
if yes:
    print("YES")
else:
    print("NO")
