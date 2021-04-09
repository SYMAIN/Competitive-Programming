"""
Did not solve last test case
"""

T = int(input())
def count(patt):
    x = patt.count("CJ")
    y = patt.count("JC")
    return (x, y)

for i in range(T):
    X, Y, patt = input().split()
    X = int(X)
    Y = int(Y)
    nQuestion = patt.count("?")
    newPatt = ""
    for j in range(len(patt)):
        if patt[j] == "?":
            continue
        else:
            newPatt += patt[j]
    x,y = count(newPatt)
    s = x*X+y*Y
    print(f"Case #{i + 1}: {s}")