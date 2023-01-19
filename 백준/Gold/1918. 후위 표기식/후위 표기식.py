s = input()
stack = []
for i in s:
    if i.isalpha():
        print(i, end="")
        continue
    elif i == '(':
        stack.append(i)
    elif i == '*' or i == '/':
        while len(stack) > 0 and (stack[-1] == '*' or stack[-1] == '/'):
            print(stack[-1], end="")
            stack.pop()
        stack.append(i)
    elif i == '+' or i == '-':
        if '(' in stack:
            while stack[-1] != '(':
                print(stack[-1], end="")
                stack.pop()
        else:
            while len(stack) > 0:
                print(stack[-1], end="")
                stack.pop()
        stack.append(i)
    elif i == ')':
        while stack[-1] != '(':
            print(stack[-1], end="")
            stack.pop()
        stack.pop()
while len(stack) > 0:
    print(stack[-1], end="")
    stack.pop()
