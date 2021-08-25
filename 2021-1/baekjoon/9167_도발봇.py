import sys

count = 0
modifier_num = 0
modified_noun_num = 0
noun_phrase_num = 0
present_rel_num = 0
past_rel_num = 0
sentence_num = 0
taunt_num = 0
present_person_num = 0
past_person_num = 0
noun_num = 0
present_verb_num = 0
past_verb_num = 0
article_num = 0
adjective_num = 0
adverb_num = 0
present_person_list = ["steed" , "king" , "first-born"]
past_person_list = ["mother" , "father" , "grandmother" , "grandfather" , "godfather"]
noun_list = ["hamster" , "coconut" , "duck" , "herring" , "newt" , "peril" , "chicken" , "vole" , "parrot" , "mouse" , "twit"]
present_verb_list = ["is" , "masquerades as"]
past_verb_list = ["was" , "personified"]
article_list = ["a"]
adjective_list = ["silly" , "wicked" , "sordid" , "naughty" , "repulsive" , "malodorous" , "ill-tempered"]
adverb_list = ["conspicuously" , "categorically" , "positively" , "cruelly" , "incontrovertibly"]


def present_person():
  global present_person_num
  global present_person_list
  result = present_person_list[present_person_num % len(present_person_list)]
  present_person_num += 1
  return result

def past_person():
  global past_person_num
  global past_person_list
  result = past_person_list[past_person_num % len(past_person_list)]
  past_person_num += 1
  return result

def noun():
  global noun_num
  global noun_list
  result = noun_list[noun_num % len(noun_list)]
  noun_num += 1
  return result

def present_verb():
  global present_verb_num
  global present_verb_list
  result = present_verb_list[present_verb_num % len(present_verb_list)]
  present_verb_num += 1
  return result

def past_verb():
  global past_verb_num
  global past_verb_list
  result = past_verb_list[past_verb_num % len(past_verb_list)]
  past_verb_num += 1
  return result

def article():
  global article_num
  global article_list
  result = article_list[article_num % len(article_list)]
  article_num += 1
  return result

def adjective():
  global adjective_num
  global adjective_list
  result = adjective_list[adjective_num % len(adjective_list)]
  adjective_num += 1
  return result

def adverb():
  global adverb_num
  global adverb_list
  result = adverb_list[adverb_num % len(adverb_list)]
  adverb_num += 1
  return result

def modifier():
  global modifier_num
  result = ""

  if modifier_num % 2 == 0:
    result = adjective()
  else:
    result = adverb() + " " + adjective()
  modifier_num += 1
  return result

def modified_noun():
  global modified_noun_num
  result = ""

  if modified_noun_num % 2 == 0:
    result = noun()
  else:
    result = modifier() + " " + noun()
  modified_noun_num += 1
  return result

def noun_phrase():
  global noun_phrase_num
  noun_phrase_num += 1

  return article() + " " + modified_noun()

def present_rel():
  global present_rel_num
  present_rel_num += 1

  return "your " + present_person() + " " + present_verb()

def past_rel():
  global past_rel_num
  past_rel_num += 1

  return "your " + past_person() + " " + past_verb()

def sentence():
  global sentence_num
  result = ""
  if sentence_num % 3 == 0:
    result = past_rel() + " " + noun_phrase()
    sentence_num += 1
  elif sentence_num % 3 == 1:
    result = present_rel() + " " + noun_phrase()
    sentence_num += 1
  elif sentence_num % 3 == 2:
    result = past_rel() + " " + article() + " " + noun()
    sentence_num += 1

  return result

def taunt(end):
  global taunt_num
  global count

  count -= 1
  # print(count)
  # print("taunt_num: ", taunt_num)
  if(end == '.\n'): sys.stdout.write("Taunter: ") 
  if taunt_num % 4 == 0:
    print(sentence().capitalize(), end=end)
  elif taunt_num % 4 == 1:
    taunt_num += 1
    taunt(' ')
    print(sentence().capitalize(), end=end)
  elif taunt_num % 4 == 2:
    print(noun().capitalize() + "!", end=end)
  elif taunt_num % 4 == 3:
    print(sentence().capitalize(), end=end)
  if(end == '.\n'): taunt_num += 1

def main():
  # python 3에서는 print() 으로 사용합니다.
  global count
  special_word = "theholygrail"

  for line in sys.stdin:
    words = list(map(str, line.split()))
    my_words = []
    sys.stdout.write("Knight: ")
    for word in words:
      sys.stdout.write(word + ' ')
    sys.stdout.write('\n')
    for word in words:
      for w in word:
        if w.isalpha():
          my_words.append(word)
          break
          
    # print(my_words)
    count = len(my_words) // 3
    if len(my_words) % 3 != 0:
      count += 1
    
    special_index = 0
    for word in my_words:
      for w in word.lower():
        if special_word[special_index] == w:
          special_index += 1
        if special_index == len(special_word): break
      if special_index == len(special_word): break
    if special_index == len(special_word):
      sys.stdout.write("Taunter: (A childish hand gesture).\n") 
      count -= 1
    while (count > 0):
      taunt('.\n')
    print()

if __name__ == "__main__":
	main()
