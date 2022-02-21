a = input()
op = input()
b = input()
alist = list(range(a))
a = list(a)

b = list(b)
if op == '*':
    for i in range(0,len(b)-1):
        a.append('0')
        
if op == '+':
    if len(b) > len(a):
        tmp = list()
        tmp = a
        a = b
        b = tmp
    a[len(a)-len(b)] = '1'
            
for j in range(0,len(a)):
    print(a[j], end='')