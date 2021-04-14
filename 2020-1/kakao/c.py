import numpy as np
def solution(info, query):
    db = []
    answer = []
    x = np.zeros((3,2,2,2,100001))
    for inf in info:
        inf = inf.split()
        inf[4] = int(inf[4])
        db.append(inf)
    db.sort()
    for d in db:
        if(d[0] == 'cpp'):
            if(d[1] == 'backend'):
                if(d[2] == 'junior'):
                    if(d[3] == 'chicken'):
                        x[0][0][0][0][d[4]] += 1
                    elif(d[3] == 'pizza'):
                        x[0][0][0][1][d[4]] += 1
                elif(d[2] == 'senior'):
                    if(d[3] == 'chicken'):
                        x[0][0][1][0][d[4]] += 1
                    elif(d[3] == 'pizza'):
                        x[0][0][1][1][d[4]] += 1
            elif(d[1] == 'frontend'):
                if(d[2] == 'junior'):
                    if(d[3] == 'chicken'):
                        x[0][1][0][0][d[4]] += 1
                    elif(d[3] == 'pizza'):
                        x[0][1][0][1][d[4]] += 1
                elif(d[2] == 'senior'):
                    if(d[3] == 'chicken'):
                        x[0][1][1][0][d[4]] += 1
                    elif(d[3] == 'pizza'):
                        x[0][1][1][1][d[4]] += 1
        elif(d[0] == 'java'):
            if(d[1] == 'backend'):
                if(d[2] == 'junior'):
                    if(d[3] == 'chicken'):
                        x[1][0][0][0][d[4]] += 1
                    elif(d[3] == 'pizza'):
                        x[1][0][0][1][d[4]] += 1
                elif(d[2] == 'senior'):
                    if(d[3] == 'chicken'):
                        x[1][0][1][0][d[4]] += 1
                    elif(d[3] == 'pizza'):
                        x[1][0][1][1][d[4]] += 1
            elif(d[1] == 'frontend'):
                if(d[2] == 'junior'):
                    if(d[3] == 'chicken'):
                        x[1][1][0][0][d[4]] += 1
                    elif(d[3] == 'pizza'):
                        x[1][1][0][1][d[4]] += 1
                elif(d[2] == 'senior'):
                    if(d[3] == 'chicken'):
                        x[1][1][1][0][d[4]] += 1
                    elif(d[3] == 'pizza'):
                        x[1][1][1][1][d[4]] += 1
        elif(d[0] == 'python'):
            if(d[1] == 'backend'):
                if(d[2] == 'junior'):
                    if(d[3] == 'chicken'):
                        x[2][0][0][0][d[4]] += 1
                    elif(d[3] == 'pizza'):
                        x[2][0][0][1][d[4]] += 1
                elif(d[2] == 'senior'):
                    if(d[3] == 'chicken'):
                        x[2][0][1][0][d[4]] += 1
                    elif(d[3] == 'pizza'):
                        x[2][0][1][1][d[4]] += 1
            elif(d[1] == 'frontend'):
                if(d[2] == 'junior'):
                    if(d[3] == 'chicken'):
                        x[2][1][0][0][d[4]] += 1
                    elif(d[3] == 'pizza'):
                        x[2][1][0][1][d[4]] += 1
                elif(d[2] == 'senior'):
                    if(d[3] == 'chicken'):
                        x[2][1][1][0][d[4]] += 1
                    elif(d[3] == 'pizza'):
                        x[2][1][1][1][d[4]] += 1
        
        
    for quer in query:
        ans = 0
        answ = ""
        quer = quer.split(' ')
        quer.remove('and')
        quer.remove('and')
        quer.remove('and')
        quer[4] = int(quer[4])
        
        q = []
        if quer[0] == '-':
            quer[0] = 'java'
            q.append(quer)
            quer[0] = 'cpp'
            q.append(quer)
            quer[0] = 'python'
            q.append(quer)
            b = []
        else:
            b = quer
            
        for qu in q:
            if qu[1] == '-':
                qu[1] = 'backend'
                b.append(qu)
                qu[1] = 'frontend'
                b.append(qu)
                c = []
            else:
                c = q
        for bu in b:
            if bu[2] == '-':
                bu[2] = 'junior'
                c.append(bu)
                bu[2] = 'senior'
                c.append(bu)
                d = []
            else:
                d = c
                
        for cu in c:
            if cu[2] == '-':
                cu[2] = 'chicken'
                d.append(cu)
                cu[2] = 'pizza'
                d.append(cu)
                
        for du in d:
            if(quer[0] == 'cpp'):
                if(quer[1] == 'backend'):
                    if(quer[2] == 'junior'):
                        if(quer[3] == 'chicken'):
                            answ = "0][0][0][0"
                        elif(quer[3] == 'pizza'):
                            answ = "0][0][0][1"
                    elif(quer[2] == 'senior'):
                        if(quer[3] == 'chicken'):
                            answ = "0][0][1][0"
                        elif(quer[3] == 'pizza'):
                            answ = "0][0][1][1"
                elif(quer[1] == 'frontend'):
                    if(quer[2] == 'junior'):
                        if(quer[3] == 'chicken'):
                            answ = "0][1][0][0"
                        elif(quer[3] == 'pizza'):
                            answ = "0][1][0][1"
                    elif(quer[2] == 'senior'):
                        if(quer[3] == 'chicken'):
                            answ = "0][1][1][0"
                        elif(quer[3] == 'pizza'):
                            answ = "0][1][1][1"
            elif(quer[0] == 'java'):
                if(quer[1] == 'backend'):
                    if(quer[2] == 'junior'):
                        if(quer[3] == 'chicken'):
                            answ = "1][0][0][0"
                        elif(quer[3] == 'pizza'):
                            answ = "1][0][0][1"
                    elif(quer[2] == 'senior'):
                        if(quer[3] == 'chicken'):
                            answ = "1][0][1][0"
                        elif(quer[3] == 'pizza'):
                            answ = "1][0][1][1"
                elif(quer[1] == 'frontend'):
                    if(quer[2] == 'junior'):
                        if(quer[3] == 'chicken'):
                            answ = "1][1][0][0"
                        elif(quer[3] == 'pizza'):
                            answ = "1][1][0][1"
                    elif(quer[2] == 'senior'):
                        if(quer[3] == 'chicken'):
                            answ = "1][1][1][0"
                        elif(quer[3] == 'pizza'):
                            answ = "1][1][1][1"
            elif(quer[0] == 'python'):
                if(quer[1] == 'backend'):
                    if(quer[2] == 'junior'):
                        if(quer[3] == 'chicken'):
                            answ = "2][0][0][0"
                        elif(quer[3] == 'pizza'):
                            answ = "2][0][0][1"
                    elif(quer[2] == 'senior'):
                        if(quer[3] == 'chicken'):
                            answ = "2][0][1][0"
                        elif(quer[3] == 'pizza'):
                            answ = "2][0][1][1"
                elif(quer[1] == 'frontend'):
                    if(quer[2] == 'junior'):
                        if(quer[3] == 'chicken'):
                            answ = "2][1][0][0"
                        elif(quer[3] == 'pizza'):
                            answ = "2][1][0][1"
                    elif(quer[2] == 'senior'):
                        if(quer[3] == 'chicken'):
                            answ = "2][1][1][0"
                        elif(quer[3] == 'pizza'):
                            answ = "2][1][1][1"
            answ = answ.split('][')
            for i in range(quer[4],100001):
                ans += x[answ[0]][answ[1]][answ[2]][answ[3]][i]
        answer.append(ans)
        # print()
        # print(quer)
    return answer