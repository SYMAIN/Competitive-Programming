lines = int(input())
var = []
y = 0
x = 0
stringg = ""

for i in range(lines):
   z = input()
   stringg += z

for i in range(len(stringg)):
   var.append(stringg[i])
    
a = var.count("t")
A = var.count("T")
b = var.count("s")
B = var.count("S")

x = a + A
y = b + B

if x > y:
    print("English")
elif x < y:
    print("French")
elif x == y:
    print("French")