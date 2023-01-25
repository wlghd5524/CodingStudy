while True:
    l = list(map(str,input().split()))
    if l[0] == "#" and l[1] == '0' and l[2] == '0':
        break
    if int(l[1]) > 17 or int(l[2]) >= 80:
        print(l[0]+" Senior")
    else:
        print(l[0]+" Junior")