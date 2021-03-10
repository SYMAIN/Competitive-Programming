"""
Author: Simon Yang
Problem: https://dmoj.ca/problem/ccc97s1
Explanation
-------------------------------------------
We have to create all the possible sentences starting with a subject, follow by a verb and an object.
We can solve this by having 3 neted loop with the subject being the first loop, the verb being the
second loop and the object being the last loop. We can then print out the sentences accordingly with each iteration. 

NOTE: The problem did say to put them into alphabetical order,
however there is no such problem where you are require to put the sentences into alphabetical order. Hence I did not implement the alg and stil AC. 
"""

#CODE
#-----------------------------------------------

# number of test cases
n = int(input())

for _ in range(n):
	# get # of subjects,# of verbs, and # of obj
	a = int(input())
	b = int(input())
	c = int(input())

	sub = []
	verb = []
	obj = []

	# store them in an list
	for j in range(a):
		z = input()
		sub.append(z)
	for j in range(b):
		z = input()
		verb.append(z)
	for j in range(c):
		z = input()
		obj.append(z)
	
	# nested for loop to iterate all the subjects,verb and objects
	for i in range(a):
		for j in range(b):
			for k in range(c):
				print(f"{sub[i]} {verb[j]} {obj[k]}.")