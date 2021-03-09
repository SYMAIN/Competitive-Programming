"""
Author: Simon Yang
Problem: https://dmoj.ca/problem/ccc96s1

Explanation
-------------------------------------------
For each number, loop through all the numbers from 1 to n and sum up all the of divisor of a number.
print out the answer according to the sum
"""

N = int(input())  # get the number of test cases

for i in range(N): # loop through the 
	n = int(input()) # get the dividend
	SUM = 0  # init sum
	for j in range(1,n): 
		if n%j == 0:  # check if the number is a factor
			SUM += j  # add up the divisor

	# compare and print out the answer
	if SUM == n:
		print(f"{n} is a perfect number.")
	elif SUM > n:
		print(f"{n} is an abundant number.")
	else:
		print(f"{n} is a deficient number.")
			