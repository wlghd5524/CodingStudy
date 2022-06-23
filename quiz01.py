enum = input().split()
for p in range(0,len(enum)):
    enum[p] = int(enum[p])
target = int(input())
breaker = False
for i in range(0,len(enum)):
    for j in range(0,len(enum)):
        if i!=j:
            if enum[i] + enum[j] == target:
                breaker = True
                break
    if breaker == True:
        break               
print(i,j)