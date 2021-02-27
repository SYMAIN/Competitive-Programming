# note this is a brute force solution

word = ["for","floor","door","transport"]
while 1:
    a = input()
    if a == "quit!": break
    if a not in word: 
        a = a.replace("or","our", 1)
    print(a)