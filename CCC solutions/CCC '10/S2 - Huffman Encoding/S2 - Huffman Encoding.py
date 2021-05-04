dict = {}
l = []
for i in range(int(input())):
    line = input().split(" ")
    dict[line[0]] = line[1]
num = input()
for i in range(len(num)):
    l.append(num[i])
    for j in range(len(l)): temp = "".join(l)
    for j in dict.items():
        if j[1] == temp:
            print(j[0],end="")
            l = []
