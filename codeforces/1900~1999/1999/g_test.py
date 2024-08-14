print(1)
x = 203
while True:
  query = input().split(' ')
  if query[0] == '!':
    answer_x = int(query[1])
    break
  a = int(query[1])
  b = int(query[2])
  w = a if a < x else a + 1
  h = b if b < x else b + 1
  area = w * h
  print(area)
