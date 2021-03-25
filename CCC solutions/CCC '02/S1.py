PINK = int(input())
GREEN = int(input())
RED = int(input())
ORANGE = int(input())
total = int(input())

cnt = 0
min = 99999999999
for npink in range(total + 1):
	for ngreen in range(total + 1):
		for nred in range(total + 1):
			for norange in range(total + 1):
				if npink * PINK + ngreen * GREEN + nred * RED + norange * ORANGE == total:
					n = npink + ngreen + nred + norange
					if n < min:
						min = n
					print(f"# of PINK is {npink} # of GREEN is {ngreen} # of RED is {nred} # of ORANGE is {norange}")
					cnt += 1

print(f"Total combinations is {cnt}.")
print(f"Minimum number of tickets to print is {min}.")