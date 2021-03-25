N = int(input())

height = list(map(int, input().split()))
width = list(map(int, input().split()))

total = 0
for i in range(len(height)-1):
    total += width[i] * (height[i] + height[i + 1]) / 2 
print(total)