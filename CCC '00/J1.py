dates = ["Sun", "Mon" ,"Tue", "Wed", "Thr", "Fri" ,"Sat"]

start,end = map(int, input().split())
current = (1 - start) + 1

cal = []
for i in range(7):
	t = []
	for j in range(7):
		if current == end + 1:
			break
		t.append(current)
		current += 1
	if t != []:
		cal.append(t)

for i in dates:
	if i == "Sat":
		print(i)
		continue
	print(i,end=" ")

for i in cal:
	for a,_date in enumerate(i):
		if _date < 0:
			print("    ",end="")
			continue
		elif _date == 0:
			print("   ",end="")
			continue
		if a == 0:
			if  _date > 9:
				print(" " + str(_date),end="")
			else:
				print("  " + str(_date),end="")
		elif _date > 9:
			print("  " + str(_date),end="")
		else:
			print("   " + str(_date),end="")
	print()