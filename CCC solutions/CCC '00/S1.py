num_of_quarter = int(input())
last_paid_S1 = int(input())
last_paid_S2 = int(input())
last_paid_S3 = int(input())
num1 = 35
num2 = 100
num3 = 10
play = 0

while num_of_quarter > 0:
    if last_paid_S1 == num1:
        num_of_quarter += 30
        num1 = num1 + 35

    if num_of_quarter <= 0:
        break
    else:
        last_paid_S1 += 1
        num_of_quarter -= 1
        play += 1

    if last_paid_S2 == num2:
        num_of_quarter += 60
        num2 = num2 + 100

    if num_of_quarter <= 0:
        break
    else:
        last_paid_S2 += 1
        num_of_quarter -= 1
        play += 1

    if last_paid_S3 == num3:
        num_of_quarter += 9
        num3 = num3 + 10

    if num_of_quarter <= 0:
        break
    else:
        last_paid_S3 += 1
        num_of_quarter -= 1
        play += 1

print("Martha plays " + str(play) + " times before going broke.")
