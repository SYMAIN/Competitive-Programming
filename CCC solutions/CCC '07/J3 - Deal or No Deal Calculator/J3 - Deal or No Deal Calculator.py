case = [100,500,1000,5000,10000,25000,50000,100000,500000,1000000]
n = int(input())
for i in range(n):
   a = int(input())
   case[a-1] = 0
bank = int(input())
average = sum(case)/(len(case)-n)
if bank > average:
   print("deal")
else:
   print("no deal")