h, m, s = input().split()
h = int(h)
m = int(m)
s = int(s)
c = input()
c = int(c)
s += c
while s >= 60 :
    s -= 60
    m += 1
    while m >= 60:
        m -= 60
        h += 1
        if h >= 24:
            h -= 24
            
    
print(str(h)+' '+str(m)+' '+str(s))
