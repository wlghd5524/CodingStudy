def solution(answers):
    first_student = [1,2,3,4,5]
    second_student = [2,1,2,3,2,4,2,5]
    third_student = [3,3,1,1,2,2,4,4,5,5]
    while len(first_student) < len(answers):
        first_student.extend(first_student)
    while len(second_student) < len(answers):
        second_student.extend(second_student)
    while len(third_student) < len(answers):
        third_student.extend(third_student)
    result = [0,0,0]
    for i in range(len(answers)):
        if first_student[i] == answers[i]:
            result[0] += 1
        if second_student[i] == answers[i]:
            result[1] += 1
        if third_student[i] == answers[i]:
            result[2] += 1
    answer = []
    for i in range(3):
        if max(result) == result[i]:
            answer.append(i+1)

    return answer