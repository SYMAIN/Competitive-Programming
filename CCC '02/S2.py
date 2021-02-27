from math import gcd

num1 = int(input())
num2 = int(input())

a = num1 // num2
b = num1 % num2

if b == 0:
  print(a)
  # quit()
else:
  if num2 % b == 0:
    num2 = num2 // b 
    b = b // b
    if a == 0:
      print(str(b) + "/" + str(num2))
    else:
      print(a, str(b) + "/" + str(num2))
  else:
    gcdNum = gcd(b, num2)
    b = b // gcdNum
    num2 = num2 // gcdNum
    if a == 0:
      print(str(b) + "/" + str(num2))
    else:
      print(a, str(b) + "/" + str(num2))
