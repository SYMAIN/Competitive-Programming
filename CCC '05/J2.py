firstnum = int(input())
secondnum = int(input())
list = []
count = 0
total = 0

for i in range(secondnum-firstnum + 1):
    list.append(firstnum + i)

for i in list:
    for j in range(1, i + 1):
        if i % j == 0:
            count += 1
    if count == 4:
        total += 1
    count = 0

print("The number of RSA numbers between",firstnum, "and", secondnum, "is", total)
