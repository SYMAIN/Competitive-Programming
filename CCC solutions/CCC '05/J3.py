directions = []
streets = []

while 1:
	direction = input()
	street = input()

	if direction == "L":
		direction = "RIGHT"
	elif direction == "R":
		direction = "LEFT"

	directions.append(direction)
	if street == "SCHOOL":
		street = "HOME"
		break
	else:
		streets.append(street)
directions = directions[::-1]
streets = streets[::-1]
streets.append("HOME")

for idx in range(len(directions)):
	if streets[idx] == "HOME":
		print(f"Turn {directions[idx]} into your HOME.")
		break
	print(f"Turn {directions[idx]} onto {streets[idx]} street.")
