weight = float(input())
height = float(input())

total = weight / (height * height)

if total < 18.5:
    print("Underweight")
elif total >= 18.5 and total <= 25:
    print("Normal weight")
elif total > 25:
    print("Overweight")