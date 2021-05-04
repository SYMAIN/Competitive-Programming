n = int(input())
list_of_numbers = []
phone_number = []
new_phone_number = []
dict = {"A": 2,
        "B": 2,
        "C": 2,
        "D": 3,
        "E": 3,
        "F": 3,
        "G": 4,
        "H": 4,
        "I": 4,
        "J": 5,
        "K": 5,
        "L": 5,
        "M": 6,
        "N": 6,
        "O": 6,
        "P": 7,
        "Q": 7,
        "R": 7,
        "S": 7,
        "T": 8,
        "U": 8,
        "V": 8,
        "W": 9,
        "X": 9,
        "Y": 9,
        "Z": 9}

for _ in range(n):
    list_of_numbers.append(input())

for i in range(n):
    phone_number.extend(list_of_numbers[i])
    for j in range(len(phone_number)):
        if phone_number[j] == "-":
            continue
        if phone_number[j] in dict:
            new_phone_number.append(dict[phone_number[j]])
        else:
            new_phone_number.append(phone_number[j])
    new_phone_number.insert(3, "-")
    new_phone_number.insert(7, "-")
    while len(new_phone_number) != 12:
        new_phone_number.pop()

    for k in range(len(new_phone_number)):
        print(new_phone_number[k], end="")
    print("")
    new_phone_number = []
    phone_number = []
