# Time Complexity = 2N (or more...)
# Space Complexity = 1

# ========= !!!importnat!!! ===========#
#                                      #
# Maximum memory usage = sum of 1 to N #
#                                      #
# ========= !!!importnat!!! ===========#

inputFile = open('deck.inp', 'r')
outputFile = open('deck.out', 'w')
N = int(inputFile.readline())
sum = N * (N + 1) // 2

i = 0
for line in inputFile:
  sum -= int(line.strip())
  i += 1
inputFile.close()

newSum = sum
median = sum // 2
sum1 = median * (median + 1) // 2
sum = N * (N + 1) // 2
sum2 = sum - sum1

inputFile = open('deck.inp', 'r')
N = int(inputFile.readline())
if i == N - 2:
  for line in inputFile:
    num = int(line.strip())
    if num <= median:
      sum1 -= num
    else:
      sum2 -= num
  outputFile.write(str(sum1) + '\n')
  outputFile.write(str(sum2) + '\n')
else:
  outputFile.write(str(newSum) + '\n')

inputFile.close()
outputFile.close()