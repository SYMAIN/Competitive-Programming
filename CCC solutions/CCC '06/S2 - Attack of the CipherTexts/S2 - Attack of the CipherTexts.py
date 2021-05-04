plainText, cor, ciphertext = input(), input(), input()
dict = {}
for i in range(len(cor)): dict[cor[i]] = plainText[i]
for i in ciphertext:
    try: print(dict[i], end="")
    except KeyError: print(".", end="")