tines = int(input())
spaces = int(input())
height = int(input())

for i in range(tines):
    print ("*" + " " * spaces + "*" + " " * spaces + "*")

print("*" * (spaces * 2 + 3) )

for i in range(height):
    print((spaces + 1) * " " + "*")