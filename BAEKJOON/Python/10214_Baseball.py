t = int(input())
Yonsei = 0
Korea = 0
for i in range(0,t):
    for j in range(0,9):
        a, b = input().split()
        a = int(a)
        b = int(b)
        Yonsei += a
        Korea += b
    if Yonsei > Korea:
        print("Yonsei")
    elif Yonsei < Korea:
        print("Korea")
    elif Yonsei == Korea:
        print("Draw")
        
        