plan_A = 0
plan_B = 0

daytime_cho = int(input())
evening_cho = int(input())
weekend_cho = int(input())

def costs_A():
    global plan_A
    if daytime_cho < 100:
        plan_A +=0
    elif daytime_cho >100:
        plan_A = (daytime_cho - 100) * 0.25
    plan_A += evening_cho * 0.15
    plan_A += weekend_cho * 0.20
    return round(plan_A, 2)


def costs_B():
    global plan_B
    if daytime_cho < 250:
        plan_B += 0
    elif daytime_cho > 250:
        plan_B = (daytime_cho - 250) * 0.45
    plan_B += evening_cho * 0.35
    plan_B += weekend_cho * 0.25
    return round(plan_B,2)

a = costs_A()
b = costs_B()
print("Plan A costs " + str(a))
print("Plan B costs " + str(b))

if a > b:
    print("Plan B is cheapest.")
if a < b:
    print("Plan A is cheapest.")
if a == b:
    print("Plan A and B are the same price.")
