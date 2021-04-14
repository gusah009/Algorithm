def solution(play_time, adv_time, logs):
    count = 0
    total = 0
    ans = 0
    answer = ''
    play_time = play_time.split(':')
    play_time = int(play_time[0]) * 3600 + int(play_time[1]) * 60 + int(play_time[2])
    print(play_time)
    adv_time = adv_time.split(':')
    adv_time = int(adv_time[0]) * 3600 + int(adv_time[1]) * 60 + int(adv_time[2])
    print(adv_time)
    play = [0 for i in range(play_time+1)]
    start = []
    end = []
    for log in logs:
        log = log.split('-')
        log[0] = log[0].split(':')
        start.append(int(log[0][0]) * 3600 + int(log[0][1]) * 60 + int(log[0][2]))
        log[1] = log[1].split(':')
        end.append(int(log[1][0]) * 3600 + int(log[1][1]) * 60 + int(log[1][2]))
    start.sort()
    end.sort()
    
    s = 0
    e = 0
    for pt in range(start[0], play_time+1):
        total += count
        while len(start) != s and start[s] == pt:
            s += 1
            count += 1
        while len(end) != e and end[e] == pt:
            e += 1
            count -= 1
        play[pt] = total
        
    answ = 0
    for pt in range(play_time + 1 - adv_time):
        if ans < (play[pt + adv_time] - play[pt]):
            ans = play[pt + adv_time] - play[pt]
            answ = pt
            
    answer = str(answ//3600).zfill(2) + ':'
    answ %= 3600
    answer += str(answ//60).zfill(2) + ':'
    answ %= 60
    answer += str(answ).zfill(2)
    print(ans)
    return answer