import requests
import pprint
import json

url = 'https://pegkq2svv6.execute-api.ap-northeast-2.amazonaws.com/prod/users'

global LEN
LEN = 5
global BOARD_SIZE
BOARD_SIZE = LEN * LEN
global moving
moving = [1,5,-1,-5]
global move
move = [True for i in range(5)]
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
    count = cnt - 4
    c = 0
    state = False
    for i in range(10):
      if loc['locations'][self.id * 5 + i]['located_bikes_count'] > 4:
        state = True
    if (trc['trucks'][self.id]['loaded_bikes_count'] != 0 and state == False) or (state):
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
          if ID % 5 == 4:
            command.append(2)
            ID += moving[1]
            move[self.id] = False
          else:
            command.append(1)
            ID += moving[0]
        else:
          if ID % 5 == 0:
            command.append(4)
            ID += moving[3]
            move[self.id] = True
          else:
            command.append(3)
            ID += moving[2]
        c += 1
        cnt = loc['locations'][ID]['located_bikes_count']
        count = cnt - 4
    else:
      command = [0,0,0,0,0,0,0,0,0,0]
    # print(self.id , " " , command)
    return command

  def trcCommand2(self, token):
    command = []
    loc = locations(token)
    trc = trucks(token)

    ID = trc['trucks'][self.id]['location_id']
    cnt = loc['locations'][ID]['located_bikes_count']
    count = cnt - 4
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
        elif ID % (LEN * 2) < 5:
          command.append(1)
          ID += moving[0]
        elif 5 <= (ID % (LEN * 2)):
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
        elif 5 <= (ID % (LEN * 2)):
          command.append(1)
          ID += moving[0]
      cnt = loc['locations'][ID]['located_bikes_count']
      count = cnt - 4
      c += 1
    # print(self.id , " " , command)
    return command


def p0_simulator():
  X_Auth_Token = 'dd6ac65a77bd2045ebabf7e2357d7f2c'
  problem = 1


  ret = start(X_Auth_Token, problem)
  token = ret['auth_key']
  print(ret)
  trc0 = Truck(0)
  sim = simulator(token, '{ "commands": [ { "truck_id": 0, "command":  [0,0,0,0,0,0,0,0,0,0] } ] }')
  trc1 = Truck(1)
  sim = simulator(token, '{ "commands": [ { "truck_id": 1, "command":  [2,0,0,0,0,0,0,0,0,0] } ] }')
  trc2 = Truck(2)
  sim = simulator(token, '{ "commands": [ { "truck_id": 2, "command":  [2,2,0,0,0,0,0,0,0,0] } ] }')
  trc3 = Truck(3)
  sim = simulator(token, '{ "commands": [ { "truck_id": 3, "command":  [2,2,2,0,0,0,0,0,0,0] } ] }')
  trc4 = Truck(4)
  while(sim.content[11:16] == b'ready'):
    data = '{ "commands": [ '
    command = trc0.trcCommand1(token)
    data += '{ "truck_id": 0, "command": ' + str(command) + '},'
    command = trc1.trcCommand1(token)
    data += '{ "truck_id": 1, "command": ' + str(command) + '},'
    command = trc2.trcCommand1(token)
    data += '{ "truck_id": 2, "command": ' + str(command) + '},'
    command = trc3.trcCommand1(token)
    data += '{ "truck_id": 3, "command": ' + str(command) + '},'
    command = trc4.trcCommand2(token)
    data += '{ "truck_id": 4, "command": ' + str(command) + '}'
    data += ' ] }'

    sim = simulator(token, data)
    pp.pprint(sim.content)
    # trc = trucks(token)
    # pp.pprint(trc['trucks'])
  pp.pprint(score(token))



if __name__ == '__main__':
  p0_simulator()
