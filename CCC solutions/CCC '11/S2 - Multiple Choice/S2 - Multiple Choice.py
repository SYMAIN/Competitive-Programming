n = int(input())
s = 0

var = [input() for i in range(n * 2)]

for i in range(n):
    if var[i] == var[i + n]:
        s +=1
    i += 1

print(s)