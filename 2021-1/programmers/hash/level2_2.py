def solution(clothes):
    answer = 1
    cloth_dict = {}
    for cloth in clothes:
        if cloth[1] in cloth_dict:
            cloth_dict[cloth[1]] += 1
        else:
            cloth_dict[cloth[1]] = 1
    
    for key in cloth_dict:
        answer *= (cloth_dict[key] + 1)
    return answer - 1