def roundTraditional(val, digits):
   return round(val+10**(-len(str(val))-1), digits)

n = int(input())
sum = 0
sum_credit = 0
for i in range(0, n):
    subject, credit, acheivement = input().split()
    credit = int(credit)
    sum_credit += credit
    if acheivement == "A+":
        sum += credit*4.3
    elif acheivement == "A0":
        sum += credit*4.0
    elif acheivement == "A-":
        sum += credit*3.7
    elif acheivement == "B+":
        sum += credit*3.3
    elif acheivement == "B0":
        sum += credit*3.0
    elif acheivement == "B-":
        sum += credit*2.7
    elif acheivement == "C+":
        sum += credit*2.3
    elif acheivement == "C0":
        sum += credit*2.0
    elif acheivement == "C-":
        sum += credit*1.7
    elif acheivement == "D+":
        sum += credit*1.3
    elif acheivement == "D0":
        sum += credit*1.0
    elif acheivement == "D-":
        sum += credit*0.7
result = str(roundTraditional(sum/sum_credit, 2))
while len(result) < 4:
    if len(result) == 1:
        result += "."
    else:
        result += "0"
print(result)
