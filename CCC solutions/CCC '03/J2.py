import math
while 1:
	n = int(input())
	if n <= 0:
		break

	for l in range(int(math.sqrt(n)),0,-1):
		if n % l == 0:
			w = n//l
			perimeter = l*2 + w*2
			print(f"Minimum perimeter is {perimeter} with dimensions {l} x {w}")
			break
	