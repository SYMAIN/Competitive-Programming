n = int(input())
m = int(input())
list_n = []
list_m = []

for i in range(n):
    list_n.append(input())
for i in range(m):
    list_m.append(input())

ide = 0
i = 0
sumn = 0

for abc in range(m * n):
    print(list_n[i] + " as " + list_m[ide])
    sumn += 1
    ide += 1
    if sumn == m:
        i += 1
        sumn = 0
        ide = 0