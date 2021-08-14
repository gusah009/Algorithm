# from collections import OrderedDict, Counter
# from math import floor, ceil

# test = [0 for _ in range(50)]

def solution(s):
    answer = ''
    s.lower()
    alphabet = {}
    for c in s:
      if c == 't':
        c = 'T'
      elif c == 'o':
        c = 'O'
      elif c == 's':
        c = 'S'
      if c in alphabet:
        alphabet[c] += 1
      else:
        alphabet[c] = 1
    
    maximum = max(alphabet.values())
    for key in alphabet.keys():
      if maximum == alphabet[key]:
        answer += key

    sorted_characters = sorted(answer)
    answer = "".join(sorted_characters)

    for key in answer:
      if key == 'S':
        answer = answer.replace("S", "SS")
      elif key == 'T':
        answer = answer.replace("T", "")
        answer = 'T' + answer
    return answer
