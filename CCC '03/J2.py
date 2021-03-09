import math

while 1:
	n = int(input())
	if n == 0:
		break
	
	l = 0
	w = 0
	perimeter = 1000000

	for i in range(1,n):
		p = (2 * (i**2) + n*2)/i
		if p <= perimeter:
			perimeter = int(p)
			l = int(i)
			w = n//l

	print(f"Minimum perimeter is {perimeter} with dimensions {l} x {w}")