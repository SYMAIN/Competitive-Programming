K = int(input())
word = input()
newWord = ""
for P,i in enumerate(word):
    s = 3*(P + 1)+K
    b = ord(i) - s
    if b < 65:
        b = b + 26
    newWord += chr(b)
print(newWord)