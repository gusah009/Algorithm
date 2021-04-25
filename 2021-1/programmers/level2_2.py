import math

def solution(progresses, speeds):
    answer = []
    days = []
    for i, v in enumerate(progresses):
        days.append(math.ceil((100 - progresses[i]) / speeds[i]))
    
    result = 1
    prev_day = days.pop(0)
    for day in days:
        if prev_day >= day:
            result += 1
        else:
            prev_day = day
            answer.append(result)
            result = 1
    answer.append(result)
    return answer