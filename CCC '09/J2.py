trouts = int(input())
pikes  = int(input())
pickerels  = int(input())
total  = int(input())

cnt = 0
for trout in range(total + 1):
	for pike in range(total + 1):
		for pickerel in range(total + 1):
			if trout == pike == pickerel == 0:
				continue
			if trout * trouts + pike * pikes + pickerel * pickerels <= total:
				print(f"{trout} Brown Trout, {pike} Northern Pike, {pickerel} Yellow Pickerel")
				cnt += 1

print(f"Number of ways to catch fish: {cnt}")
