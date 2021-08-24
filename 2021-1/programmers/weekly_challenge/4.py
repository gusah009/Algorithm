answer = ''
jobs = {}
result = {}

for row in table:
    l = row.split()
    jobs[l[0]] = l[1:]
    result[l[0]] = 0

for i in range(len(languages)):
  main_lang = languages[i]
  for job, langs in jobs.items():
    score = 5
    for lang in langs:
      if lang == main_lang:
        break
      score -= 1
    result[job] += score * preference[i]

maximum = max(result.values())


# for job in result:
#   print(result[job])
for job in sorted(result):
  if result[job] == maximum:
    answer = job
    break

