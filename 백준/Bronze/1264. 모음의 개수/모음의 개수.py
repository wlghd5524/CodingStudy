while True:  
    s = input()
    if s == "#":
        break
    cnt = 0
    for i in s:
        if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u' or i == 'A' or i == 'E' or i == 'I' or i == 'O' or i == 'U':
            cnt += 1
    print(cnt)