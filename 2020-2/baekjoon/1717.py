import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, M = map(int, input().split())
parent = [i for i in range(N + 1)]

def getParent(n):
  if parent[n] == n:
    return n
  parent[n] = getParent(parent[n])
  return parent[n]

for m in range(M):
  opt, a, b = map(int, input().split())
  a = getParent(a)
  b = getParent(b)
  if opt == 0:
    if a > b:
      parent[a] = b
    else:
      parent[b] = a
  if opt == 1:
    if a == b:
      print("YES")
    else:
      print("NO")
  # print(parent)