for i in range(3):
    l = list(map(int, input().split()))
    if sum(l) == 0:
        print('D')
    elif sum(l) == 1:
        print('C')
    elif sum(l) == 2:
        print('B')
    elif sum(l) == 3:
        print('A')
    else:
        print('E')
