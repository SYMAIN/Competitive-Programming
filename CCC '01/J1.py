n = int(input())

for i in range(1, n, 2):
    temp = (n + n - 2 - 2 * i)
    print("*" * i, " " * temp, "*" * i)
print("*" * n * 2)
for i in reversed(range(1, n, 2)):
    temp = (n + n - 2 - 2 * i)
    print("*" * i, " " * temp, "*" * i)
