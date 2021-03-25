"""
Author: Simon Yang
Problem: https://dmoj.ca/problem/ccc96s5
Explanation
-------------------------------------------
Given 2 set of numbers, we must find the maxiumum distance between two elements such that the larger
index must contain a value larger or equal to the value of the index. For example if we have a list X
with an index of i and list Y with the index of j, then the maximum distance would be j - i with y[j] 
bigger than or equal to X[i].
"""

# CODE
#-----------------------------------------------
N = int(input())  # get numbers of test cases

for i in range(N):  # loop through all test cases
	X = int(input()) # get length of list

	# get string and seperate them into int and store them in a list
	l1 = list(map(int,input().split(' ')))
	l2 = list(map(int,input().split(' ')))
	
	maximum = 0  # init maximum
	for j in range(X):  # loop through the list
		for k in reversed(range(X)):  # loop through the list
			if (l2[k] >= l1[j] and k-j>maximum):  # check constraints
				maximum = k-j  # set differences to maximum
	print(f"The maximum distance is {maximum}")  # print out maximum distance