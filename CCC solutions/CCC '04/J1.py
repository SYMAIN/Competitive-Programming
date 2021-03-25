import math
n = int(input())

s = math.sqrt(n)
result = round(s)

if result > s:
    result -= 1
print(f"The largest square has side length {result}.")
