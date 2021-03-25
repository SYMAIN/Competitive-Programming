total = 1

while True:
    steps = int(input())
    total += steps
    if steps == 0:
        print("You Quit!")
        break
    elif total > 100:
        total -= steps
    elif total == 100:
        print("You are now on square 100")
        print("You Win!")
        break

    if total == 9:
        total = 34
    elif total == 40:
        total = 64
    elif total == 67:
        total = 86
    elif total == 99:
        total = 77
    elif total == 90:
        total = 48
    elif total == 54:
        total = 19

    print("You are now on square " + str(total))
