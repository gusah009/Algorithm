inputFile = open('words.inp', 'r')
outputFile = open('words.out', 'w')
N = inputFile.readline()
N.strip()
N = int(N)

myDic = {}

flag = True
for line in inputFile:
  line = line.strip()
  if myDic.get(line) is None:
    myDic[line] = 1
  else:
    myDic[line] += 1
    if myDic[line] > N // 2:
      outputFile.writelines(line)
      flag = False
      break

if flag == True:
  outputFile.writelines('NONE')


inputFile.close()
outputFile.close()