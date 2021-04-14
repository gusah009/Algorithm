from itertools import combinations

def solution(orders, course):
    answe = [0 for i in range(11)]
    tmp_answer = [[] for row in range(11)]
    a = []
    tmpa = []
    answer = []
    for order in orders:
        for alp in order:
            if alp not in a:
                a.append(alp)
    
    for cour in course:
        a.sort()
        b = list(combinations(a,cour))
        
        for c in b:
            answ = 0
            for order in orders:
                ans = 0
                for d in c:
                    if d in order:
                        ans += 1
                if ans == cour:
                    answ += 1
            if answ >= 2:
                for alp in c:
                    if alp not in tmpa:
                        tmpa.append(alp)
                if answe[cour] < answ:
                    answe[cour] = answ
                    tmp_answer[cour] = ''.join(c)
                elif answe[cour] == answ:
                    tmp_answer[cour] += ' '
                    tmp_answer[cour] += ''.join(c)
        a = tmpa
        tmpa = []
    
    for i in tmp_answer:
        if type(i) == type(""):
            i = i.split()
            for j in i:
                answer.append(j)
    answer.sort()
    return answer