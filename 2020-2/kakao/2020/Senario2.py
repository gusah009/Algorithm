import requests
import pprint
import json

url = 'https://pegkq2svv6.execute-api.ap-northeast-2.amazonaws.com/prod/users'

global LEN
LEN = 60
global BOARD_SIZE
BOARD_SIZE = LEN * LEN
global moving
moving = [1,5,-1,-5]
global move
move = [True for i in range(10)]
global pp
pp = pprint.PrettyPrinter(indent=2)

def start(X_AUTH_TOKEN, problem):
  headers = {
      'X-Auth-Token': X_AUTH_TOKEN,
      'Content-Type': 'application/json',
  }

  data = '{ "problem": '+ str(problem) + ' }'
  uri = url + '/start'
  return requests.post(uri, headers=headers, data=data).json()


def locations(token):
  uri = url + '/locations'
  return requests.get(uri, headers={'Authorization': token}).json()


def trucks(token):
  uri = url + '/trucks'
  return requests.get(uri, headers={'Authorization': token}).json()

def simulator(token, data):
  headers = {
    'Authorization': token,
    'Content-Type': 'application/json',
  }

  uri = url + '/simulate'
  return requests.put(uri, headers=headers, data=data)

def score(token):
  uri = url + '/score'
  return requests.get(uri, headers={'Authorization': token}).json()

class Truck():
  def __init__(self, id):
    self.id = int(id)
  def trcCommand1(self, token):
    command = []
    loc = locations(token)
    trc = trucks(token)

    ID = trc['trucks'][self.id]['location_id']
    cnt = loc['locations'][ID]['located_bikes_count']
    count = cnt - 3
    c = 0
    state = False
    while c < 10: # Truck 1분동안 할 수 있는 행동 수
      while count > 0:
        if c == 10:
          break
        command.append(5)
        # pp.pprint(loc['locations'][ID]['located_bikes_count'])
        count -= 1
        c += 1
      if trc['trucks'][self.id]['loaded_bikes_count'] != 0:
        while count < 0:
          if c == 10:
            break
          command.append(6)
          # pp.pprint(loc['locations'][ID]['located_bikes_count'])
          count += 1
          c += 1
      if c == 10:
        break
      
      if move[self.id]:
        if ID == BOARD_SIZE - 1:
          command.append(3)
          ID += moving[2]
          move[self.id] = False
        elif ID % (LEN * 2) == 4 or ID % (LEN * 2) == 5:
          command.append(2)
          ID += moving[1]
        elif ID % (LEN * 2) < 60:
          command.append(1)
          ID += moving[0]
        elif 60 <= (ID % (LEN * 2)):
          command.append(3)
          ID += moving[2]
      else:
        if ID == 0:
          command.append(1)
          ID += moving[0]
          move[self.id] = True
        elif ID % (LEN * 2) == 0 or ID % (LEN * 2) == 9:
          command.append(4)
          ID += moving[3]
        elif ID % (LEN * 2) < 60:
          command.append(3)
          ID += moving[2]
        elif 60 <= (ID % (LEN * 2)):
          command.append(1)
          ID += moving[0]
      c += 1
      cnt = loc['locations'][ID]['located_bikes_count']
      count = cnt - 3
    # print(self.id , " " , command)
    return command

    def trcCommand2(self, token):
      command = []
      loc = locations(token)
      trc = trucks(token)

      ID = trc['trucks'][self.id]['location_id']
      cnt = loc['locations'][ID]['located_bikes_count']
      count = loc['locations'][ID]['located_bikes_count'] - 3
      for i in range(10): # Truck 1분동안 할 수 있는 행동 수
        if count > 0:
          command.append(5)
          # pp.pprint(loc['locations'][ID]['located_bikes_count'])
          count -= 1
        elif count < 0:
          command.append(6)
          # pp.pprint(loc['locations'][ID]['located_bikes_count'])
          count += 1
        else:
          if move[self.id]:
            if ID == BOARD_SIZE - 1:
              command.append(3)
              ID += moving[2]
              move[self.id] = False
            elif ID % (LEN * 2) == 4 or ID % (LEN * 2) == 5:
              command.append(2)
              ID += moving[1]
            elif ID % (LEN * 2) < 5:
              command.append(1)
              ID += moving[0]
            elif 5 <= ID % (LEN * 2):
              command.append(3)
              ID += moving[2]
          else:
            if ID == 0:
              command.append(1)
              ID += moving[0]
              move[self.id] = True
            elif ID % (LEN * 2) == 0 or ID % (LEN * 2) == 9:
              command.append(4)
              ID += moving[3]
            elif ID % (LEN * 2) < 5:
              command.append(3)
              ID += moving[2]
            elif 5 <= ID % (LEN * 2):
              command.append(1)
              ID += moving[0]
          cnt = loc['locations'][ID]['located_bikes_count']
          count = loc['locations'][ID]['located_bikes_count'] - 4


def p0_simulator():
  X_Auth_Token = 'dd6ac65a77bd2045ebabf7e2357d7f2c'
  problem = 2


  ret = start(X_Auth_Token, problem)
  token = ret['auth_key']
  print(ret)
  trc = []
  for i in range(10):
    trc.append(Truck(i))
  for k in range(2):
    command = []
    data = '{ "commands": [ '
    for i in range(10):
      for j in range(10):
        if j < i:
          command.append(2)
        else:
          command.append(0)
      if i != 9:
        data += '{ "truck_id": '+ str(i) +', "command":  '+ str(command) +' },'
      else:
        data += '{ "truck_id": '+ str(i) +', "command":  '+ str(command) +' }'
    data += ' ] }'
    sim = simulator(token, data)
    print(sim.content)
    
  while(sim.content[11:16] == b'ready'):
    data = '{ "commands": [ '
    for i in range(5):
      command = trc[i].trcCommand1(token)
      if i != 4:
        data += '{ "truck_id": '+ str(i) +', "command":  '+ str(command) +' },'
      else:
        data += '{ "truck_id": '+ str(i) +', "command":  '+ str(command) +' }'
    data += ' ] }'

    sim = simulator(token, data)
    pp.pprint(sim.content)
    # trc = trucks(token)
    # pp.pprint(trc['trucks'])
  pp.pprint(score(token))



if __name__ == '__main__':
  p0_simulator()
