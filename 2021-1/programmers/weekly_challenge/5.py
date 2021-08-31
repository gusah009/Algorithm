answer = 0

def vowel_check(my_word, word):
    if my_word == word:
        return True
    if len(my_word) == 5:
        return False
    global answer
    vowels = ['A', 'E', 'I', 'O', 'U']
    for vowel in vowels:
        answer += 1
        if vowel_check(my_word + vowel, word):
            return True
    return False
    
    
def solution(word):
    global answer
    vowel_check('', word)
    return answer