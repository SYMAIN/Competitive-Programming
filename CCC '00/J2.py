start = int(input())
end = int(input())
cnt = 0

dic = {
	0:0,
	1:1,
	6:9,
	8:8,
	9:6
}

for number in range(start,end + 1):
	newNumber = ""
	for n in str(number):
		if int(n) in dic.keys():
			newNumber += str(dic[int(n)])
	newNumber = newNumber[::-1]
	if newNumber == "":
		continue
	if int(newNumber) == number:
		cnt += 1
print(cnt)