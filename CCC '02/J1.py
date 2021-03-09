n = int(input())

sec1 = " * * *"
sec2 = "*     *"

sec3 = "      *"
sec4 = "*"

sec5 = ""

arry = {}

arry[0] = [sec1,sec2,sec2,sec2,sec5,sec2,sec2,sec2,sec1]
arry[1] = [sec5,sec3,sec3,sec3,sec5,sec3,sec3,sec3,sec5]
arry[2] = [sec1,sec3,sec3,sec3,sec1,sec4,sec4,sec4,sec1]
arry[3] = [sec1,sec3,sec3,sec3,sec1,sec3,sec3,sec3,sec1]
arry[4] = [sec5,sec2,sec2,sec2,sec1,sec3,sec3,sec3,sec5]
arry[5] = [sec1,sec4,sec4,sec4,sec1,sec3,sec3,sec3,sec1]
arry[6] = [sec1,sec4,sec4,sec4,sec1,sec2,sec2,sec2,sec1]
arry[7] = [sec1,sec3,sec3,sec3,sec5,sec3,sec3,sec3,sec5]
arry[8] = [sec1,sec2,sec2,sec2,sec1,sec2,sec2,sec2,sec1]
arry[9] = [sec1,sec2,sec2,sec2,sec1,sec3,sec3,sec3,sec1]

for i in range(len(arry[n])):
	print (arry[n][i])
