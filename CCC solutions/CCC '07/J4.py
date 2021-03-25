import string

line1 = input().lower()
line2 = input().lower()
total = 0

for x in string.ascii_lowercase:
    if line1.count(x) < line2.count(x):
        print("Is not an anagram.")
        break
else:
    print("Is an anagram.")