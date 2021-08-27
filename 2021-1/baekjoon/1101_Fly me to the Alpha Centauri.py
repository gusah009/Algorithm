import sys

def main():
  T = int(input())
  for _ in range(T):
    line = sys.stdin.readline()
    x, y = list(map(int, line.split()))
    dist = y - x
    count = 0
    i = 1
    while(True):
      for j in range(2):
        dist -= i
        count += 1
        if dist <= 0: break
      if dist <= 0: break
      i += 1
    sys.stdout.write(str(count) + '\n')

if __name__ == "__main__":
	main()
