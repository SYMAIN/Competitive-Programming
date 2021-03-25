list = []
num = []

while True:
    city = input().split(" ")
    for i in range(2):
        list.append(city[i])
    num.append(int(city[1]))
    num.sort()
    if "Waterloo" in city:
        break

for i in range(len(list)):
    if str(num[0]) == list[i]:
        print(list[i - 1])
