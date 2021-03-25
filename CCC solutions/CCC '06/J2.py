n = int(input())
m = int(input())
summ = 0
x = 1
y = 0

while True:
    x += 1
    if x + (m - y) == 10:
        summ += 1
    if x == n or x >= 10:
        y += 1
        x = 0
    if (m - y) <= 0:
        break
if summ == 1:
    print("There is " + str(summ) + " way to get the sum 10.")
else:
    print("There are " + str(summ) + " ways to get the sum 10.")
