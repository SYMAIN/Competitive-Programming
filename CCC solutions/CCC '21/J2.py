N = int(input())
save = []

for i in range(N):
    name = input()
    x = int(input())
    save.append((name,x))

max = 0
str = ""
for i in range(len(save)):
    if save[i][1] > max:
        max = save[i][1]
        str = save[i][0]
print(str)
