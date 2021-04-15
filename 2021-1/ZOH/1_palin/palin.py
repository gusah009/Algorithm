inputFile = open('palin.inp', 'r')
outputFile = open('palin.out', 'w')
inputFile.readline()

line1 = ""
line2 = ""
for line in inputFile:
  line = line.strip()
  flag = True
  for i, alp in enumerate(line):
    if len(line)//2 == i:
      if flag == True:
        outputFile.writelines('1\n')
      else:
        outputFile.writelines('2\n')
      break
    if line[i] != line[-i-1]:
      flag = False
      line1 = line[:i] + line[i+1:]
      if i == 0:
        line2 = line[:-1]
      else:
        line2 = line[:-i-1] + line[-i:]
      break
  flag2 = True
  if flag == False:
    for i, alp in enumerate(line1):
      if len(line1)//2 == i:
        flag2 = False
        outputFile.writelines('2\n')
        break
      if line1[i] != line1[-i-1]:
        break
    if flag2 == True:
      for i, alp in enumerate(line2):
        if len(line2)//2 == i:
          outputFile.writelines('2\n')
          break
        if line2[i] != line2[-i-1]:
          outputFile.writelines('3\n')
          break


  # print(line)
inputFile.close()
outputFile.close()