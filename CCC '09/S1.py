import math

start = int(input())
end = int(input())

cnt = 0

for i in range(1,100):
	val = (i * i * i) ** 2
	if val >= start and val <= end:
		cnt += 1

print(cnt)

""" 
(1*1*1)^2
(2*2*2)^2
(3*3*3)^2
(4*4*4)^2
(5*5*5)^2
"""