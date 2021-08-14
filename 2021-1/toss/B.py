from collections import OrderedDict

def solution(param0):
  answer = [-1 for _ in range(len(param0))]
  isLoan = False
  first_money = 100000000
  moneyDict = OrderedDict()
  moneyDict_loan = OrderedDict()


  for current_day, money in enumerate(param0):
    remove_days = []
    moneyDict= OrderedDict(sorted(moneyDict.items(), key=lambda item: item[1]['purchase_money'], reverse=True))
    for day, value in moneyDict.items():
      if (value['purchase_money'] >= money * 2):
        value['stock'] += (value['remain'] + 50000000) // money
        moneyDict_loan[day] = {'stock': value['stock']}
        remove_days.append(day)
      else:
        break
    for remove_day in remove_days:
      del moneyDict[remove_day]
    
    remove_days = []
    moneyDict = OrderedDict(sorted(moneyDict.items(), key=lambda item: item[1]['stock'], reverse=True))
    for day, value in moneyDict.items():
      if (value['stock'] * money >= 1000000000):
        remove_days.append(day)
        answer[day] = current_day - day
      else:
        break
    for remove_day in remove_days:
      del moneyDict[remove_day]

    remove_days = []
    moneyDict_loan = OrderedDict(sorted(moneyDict_loan.items(), key=lambda item: item[1]['stock'], reverse=True))
    # for day, value in moneyDict.items():
    #   print(day, value, current_day, money)
    for day, value in moneyDict_loan.items():
      if (value['stock'] * money >= 1050000000):
        remove_days.append(day)
        answer[day] = current_day - day
        # print(current_day - day, answer[day])
      else:
        break
    for remove_day in remove_days:
      del moneyDict_loan[remove_day]

    current_stock = first_money // money
    remain = first_money % money
    moneyDict[current_day] = {'stock': current_stock, 'purchase_money': money, 'remain': remain}

    return answer