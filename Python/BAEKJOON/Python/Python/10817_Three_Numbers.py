#문제
#세 정수 A, B, C가 주어진다. 이때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오. 

#입력
#첫째 줄에 세 정수 A, B, C가 공백으로 구분되어 주어진다. (1 ≤ A, B, C ≤ 100)

#출력
#두 번째로 큰 정수를 출력한다.
l = [0,0,0]
a,b,c = input().split()
a = int(a)
b = int(b)
c = int(c)
l[0] = a
l[1] = b
l[2] = c
l.sort(reverse=True)
print(l[1])