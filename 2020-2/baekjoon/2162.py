import sys
input = sys.stdin.readline

parent = []
s = []

def ccw(p1, p2, p3):
    temp = (p1[0] * p2[1]) + (p2[0] * p3[1]) + (p3[0] * p1[1])
    temp = temp - (p1[1] * p2[0]) - (p2[1] * p3[0]) - (p3[1] * p1[0])
    if temp > 0:
        return 1
    elif temp < 0:
        return -1
    else:
        return 0

def checkCross(li1, li2):
    li1p1 = [li1[0], li1[1]]
    li1p2 = [li1[2], li1[3]]
    li2p1 = [li2[0], li2[1]]
    li2p2 = [li2[2], li2[3]]
    result1 = ccw(li1p1, li1p2, li2p1) * ccw(li1p1, li1p2, li2p2)
    result2 = ccw(li2p1, li2p2, li1p1) * ccw(li2p1, li2p2, li1p2)
    if result1 <= 0 and result2 <= 0:
        if ((li1p1[0] > li2p1[0] and li1p1[0] > li2p2[0] and li1p2[0] > li2p1[0] and li1p2[0] > li2p2[0]) 
        or (li1p1[0] < li2p1[0] and li1p1[0] < li2p2[0] and li1p2[0] < li2p1[0] and li1p2[0] < li2p2[0])):
            return False
        elif ((li1p1[1] > li2p1[1] and li1p1[1] > li2p2[1] and li1p2[1] > li2p1[1] and li1p2[1] > li2p2[1]) 
        or (li1p1[1] < li2p1[1] and li1p1[1] < li2p2[1] and li1p2[1] < li2p1[1] and li1p2[1] < li2p2[1])):
            return False
        else:
            return True
    return False

def getParent(a):
    if parent[a] == a:
        return a
    else:
        parent[a] = getParent(parent[a])
        return parent[a]
def union(x, y):
    parentX = getParent(x)
    parentY = getParent(y)
    if parentX > parentY:
        parent[parentX] = parentY
    elif parentY > parentX:
        parent[parentY] = parentX

N = int(input())
disjoint_set_list = []
maximum = 0
for i in range(N):
  segmant = input()
  segmant = list(map(int, segmant.split(' ')))
  s.append(segmant)
  parent.append(i)
for i in range(N - 1):
  for j in range(i + 1, N):
    if checkCross(s[i], s[j]):
        union(i, j)
cnt = 0
max_num = 0
parent_ = [0 for i in range(N)]
for i in range(N):
    if parent[i] == i:
        cnt += 1
    parent_[getParent(i)] += 1
    if parent_[getParent(i)] > max_num:
        max_num = parent_[getParent(i)]
print(cnt)
print(max_num)