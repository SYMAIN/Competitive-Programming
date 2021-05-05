speedLimit = int(input())
recordedSpeed = int(input())
total = 0

if speedLimit - recordedSpeed  >= 0:
    print("Congratulations, you are within the speed limit!")
elif speedLimit - recordedSpeed  <= -1 and speedLimit - recordedSpeed  >= -20:
    print("You are speeding and your fine is $100.")
elif speedLimit - recordedSpeed  <= -21 and speedLimit - recordedSpeed  >= -30:
    print("You are speeding and your fine is $270.")
elif speedLimit - recordedSpeed  <= -31:
    print("You are speeding and your fine is $500.")